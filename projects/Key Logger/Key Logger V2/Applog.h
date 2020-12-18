#pragma once

#ifndef _APPLOG_H_
#define _APPLOG_H_

#include <string>
#include <sstream>
#include <fstream>

#include "DateTimeHelper.h"

constexpr auto DEFAULT_LOG_DIR = "";

class ApplicationLog {
	public:
		std::fstream _log_file;
		std::string _log_dir;

		ApplicationLog() {
			this->_log_dir = DEFAULT_LOG_DIR; // current directory of the program .exe file
		}

		ApplicationLog(const std::string& log_dir = DEFAULT_LOG_DIR) {
			this->_log_dir = log_dir;
		}

		std::string GetLogFileName() {
			return "default_app_log.txt"; // for now
		}

		void WriteToLog(const std::string& message) {
			std::string date_time_stamp = DateTime::GetCurrentDateTimeString();
			std::string log_entry = date_time_stamp + "\t: " + message;
			if (!this->_log_file)
				this->OpenLogFile();
			this->_log_file << log_entry << std::endl;
			return;
		}

		void OpenLogFile() {
			this->_log_file.open(this->GetLogFileName(), std::ios::app);
			if (!this->_log_file) {
				std::cout << "Error Opening Log File!" << std::endl;
			}
		}
};

namespace AppLog {

	static ApplicationLog *_log_object = nullptr;

	void InitializeApplicationLog(const std::string& log_dir = DEFAULT_LOG_DIR) {
		if (AppLog::_log_object == nullptr) {
			AppLog::_log_object = new ApplicationLog(log_dir);
			AppLog::_log_object->OpenLogFile();
		}
		return;
	}

	void Write(const std::string& message) {
		AppLog::_log_object->WriteToLog(message);
		return;
	}

	void CloseApplicationLog() {
		if (AppLog::_log_object != nullptr) {
			AppLog::_log_object->_log_file.close();
			delete AppLog::_log_object;
		}
		return;
	}
}

#endif // _APPLOG_H_