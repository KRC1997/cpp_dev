#pragma once

#ifndef _DATETIMEHELPER_H_
#define _DATETIMEHELPER_H_

#include <string>
#include <ctime>
#include <chrono>

#include "Utility.h"

class DateTime {
private:
	DateTime() {
		this->date = this->month = this->year = 0;
		this->ns = this->us = this->ms = 0;
		this->s = this->m = this->h = 0;
	}

	DateTime(short d, short m, short y) {
		this->date = d;
		this->month = m;
		this->year = y;
		this->ns = this->us = this->ms = 0;
		this->s = this->m = this->h = 0;
	}

	DateTime(short n_s, short u_s, short m_s, short _s, short _m, short _h) {
		this->date = this->month = this->year = 0;
		this->ns = n_s;
		this->us = u_s;
		this->ms = m_s;
		this->s = _s;
		this->m = _m;
		this->h = _h;
	}

	DateTime(short d, short m, short y, short n_s, short u_s, short m_s, short _s, short _m, short _h) {
		this->date = d;
		this->month = m;
		this->year = y;
		this->ns = n_s;
		this->us = u_s;
		this->ms = m_s;
		this->s = _s;
		this->m = _m;
		this->h = _h;
	}

	static DateTime * _GetCurrentDateTime() {
		std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
		time_t tt = std::chrono::system_clock::to_time_t(now);
		tm local_tm; localtime_s(&local_tm, &tt);

		typedef std::chrono::duration<int, std::ratio_multiply<std::chrono::hours::period, std::ratio<24>>::type> days;
		std::chrono::system_clock::duration tp = now.time_since_epoch();
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		auto h = std::chrono::duration_cast<std::chrono::hours>(tp);
		tp -= h;
		auto m = std::chrono::duration_cast<std::chrono::minutes>(tp);
		tp -= m;
		auto s = std::chrono::duration_cast<std::chrono::seconds>(tp);
		tp -= s;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp);
		tp -= ms;
		auto us = std::chrono::duration_cast<std::chrono::microseconds>(tp);
		tp -= us;
		auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(tp);

		short date = local_tm.tm_mday, month = local_tm.tm_mon + 1, year = local_tm.tm_year + 1900;
		short hours = local_tm.tm_hour, minutes = local_tm.tm_min, seconds = local_tm.tm_sec;
		short milliseconds = ms.count(), microseconds = us.count(), nanoseconds = ns.count();
		return new DateTime(date, month, year, nanoseconds, microseconds, milliseconds, seconds, minutes, hours);
	}

public:
	short date, month, year;
	// nano_seconds, micro_seconds, milli_seconds, seconds, minutes, hours
	short ns, us, ms, s, m, h;

	static std::string GetCurrentDateString(const std::string& date_sep = "-") {
		DateTime* cdt = DateTime::_GetCurrentDateTime();
		std::string result = "[";
		result += (cdt->date < 10) ? ("0") : ("");
		result += Utility::ToString(cdt->date) + date_sep;
		result += ((cdt->month < 10) ? ("0") : ("")) + Utility::ToString(cdt->month) + date_sep;
		result += Utility::ToString(cdt->year) + "]";
		delete cdt;
		return result;
	}

	static std::string GetCurrentTimeString(const std::string& time_sep = ":") {
		DateTime* cdt = DateTime::_GetCurrentDateTime();
		std::string result = "[";
		result += ((cdt->h < 10) ? ("0") : ("")) + Utility::ToString(cdt->h) + time_sep;
		result += ((cdt->m < 10) ? ("0") : ("")) + Utility::ToString(cdt->m) + time_sep;
		result += ((cdt->s < 10) ? ("0") : ("")) + Utility::ToString(cdt->s) + time_sep;
		result += ((cdt->ms < 10) ? ("0") : ("")) + Utility::ToString(cdt->ms) + time_sep;
		result += ((cdt->us < 10) ? ("0") : ("")) + Utility::ToString(cdt->us) + time_sep;
		result += ((cdt->ns < 10) ? ("00") : ("")) + Utility::ToString(cdt->ns) + "]";
		delete cdt;
		return result;
	}

	static std::string GetCurrentDateTimeString(const std::string& date_sep = "-", const std::string& time_sep = ":") {
		DateTime* cdt = DateTime::_GetCurrentDateTime();
		std::string result = "[";
		result += (cdt->date < 10) ? ("0") : ("");
		result += Utility::ToString(cdt->date) + date_sep;
		result += ((cdt->month < 10) ? ("0") : ("")) + Utility::ToString(cdt->month) + date_sep;
		result += Utility::ToString(cdt->year) + "] [";
		result += ((cdt->h < 10) ? ("0") : ("")) + Utility::ToString(cdt->h) + time_sep;
		result += ((cdt->m < 10) ? ("0") : ("")) + Utility::ToString(cdt->m) + time_sep;
		result += ((cdt->s < 10) ? ("0") : ("")) + Utility::ToString(cdt->s) + time_sep;
		result += ((cdt->ms < 10) ? ("0") : ("")) + Utility::ToString(cdt->ms) + time_sep;
		result += ((cdt->us < 10) ? ("0") : ("")) + Utility::ToString(cdt->us) + time_sep;
		result += ((cdt->ns < 10) ? ("00") : ("")) + Utility::ToString(cdt->ns) + "]";
		delete cdt;
		return result;
	}

	static DateTime* GetCurrentDateTime() {
		return DateTime::_GetCurrentDateTime();
	}
};

# endif // _DATETIMEHELPER_H_