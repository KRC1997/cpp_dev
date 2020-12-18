#pragma once


#ifndef _HELPER_H_
#define _HELPER_H_

#include <ctime>
#include <string>
#include <fstream>

// this header provides functions for string conversion
#include <sstream> 

namespace Helper {
	/*
		lambda expression to tell the compiler what data type
		this function will return
	*/
	template <typename T>
	auto ToString(const T& object)->std::string {
		std::ostringstream output_string_stream;
		output_string_stream << object;
		return output_string_stream.str();
	}

	/*
		Custom DateTime structure for logging purpose
	*/
	struct DateTime {
		int d, m, y;
		int s, min, h;

		DateTime() {
			time_t milli_seconds;
			time(&milli_seconds);
			struct tm info;
			localtime_s(&info, &milli_seconds);
			d = info.tm_mday;
			m = info.tm_mon + 1; // 0 based index for months
			y = 1900 + info.tm_year;
			min = info.tm_min;
			h = info.tm_hour;
			s = info.tm_sec;
		}

		DateTime(int date, int month, int year, int minute, int hour, int second) {
			d = date;
			m = month;
			y = year;
			min = minute;
			h = hour;
			s = second;
		}

		DateTime(int date, int month, int year) {
			d = date;
			m = month;
			y = year;
			s = 0;
			min = 0;
			h = 0;
		}

		DateTime Now() const {
			return DateTime();
		}

		auto GetDateString() const->std::string {
			return std::string(d < 10 ? "0" : "") + ToString(d) +
				std::string(m < 10 ? ".0" : ".") + ToString(m) +
				ToString(y);
		}

		// passing an argument for separator, default is ':'
		auto GetTimeString(const std::string sep = ":") const->std::string {
			return std::string(h < 10 ? "0" : "") + ToString(h) + sep +
				std::string(m < 10 ? "0" : "") + ToString(m) + sep +
				std::string(s < 10 ? "0": "") + ToString(s);
		}

		auto GetDateTimeString(const std::string sep = ":") const->std::string {
			return GetDateString() + " " + GetTimeString(sep);
		}

	};

	/*
		This function records the behavior of the Key Logger, not the keys being pressed
	*/
	void WriteAppLog(const std::string& s) {
		std::ofstream file("AppLog.txt", std::ios::app);
		file << "[" << Helper::DateTime().GetDateTimeString() << "]\n" << std::endl;
		file << s << std::endl << "\n";
		file.close();
	}
}

#endif // _HELPER_H_