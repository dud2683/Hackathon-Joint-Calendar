#pragma once
#include "Common.h"
struct TimeDuration {
	TimeDuration(uint32_t hours, uint32_t minutes)
		:
		hours(hours),
		minutes(minutes)
	{}

	const uint32_t minutes, hours;
};
struct Date {

public:
	
	enum class Month {
		Invalid = 0,
		January = 1,
		February = 2,
		March = 3,
		April = 4,
		May = 5,
		June = 6,
		July = 7,
		August = 8,
		September = 9,
		October = 10,
		November = 11,
		December = 12
	};
	static Month StringToMonth(std::string s);

public:

	void PrintMonth();
	Date() = default;

public:

	Date(uint32_t day, Month month, uint32_t year) :
		day(day),
		month(month),
		year(year)
	{
	}
public:
	static bool ValidateDate(uint32_t day, Month month, uint32_t year);

public:

	static Date CreateDate(uint32_t day, Month month, uint32_t m_year);
	void PrintDate();
	uint32_t day;
	Month month;
	uint32_t year;
};
struct Time {
public:

	Time(uint32_t minute, uint32_t hour) :
		minute(minute),
		hour(hour)
	{}
	
public:
	static bool ValidateTime(uint32_t minute, uint32_t hour);
	bool operator > (Time& rhs) {
		if (this->hour > rhs.hour)
			return true;
		else if (this->hour == rhs.hour) {
			return this->minute > rhs.minute;
		}
		else
			return false;
	}
	static Time CreateTime(uint32_t minute, uint32_t hour);
	void PrintTime();
	uint32_t minute;
	uint32_t hour;
};
class TimePoint
{
	
public:
	TimePoint() 
		:
		m_date(0,Date::Month(0),0),
		m_time(0,0)
	{
	
	};
	TimePoint(Time time, Date date);
	static TimePoint CreateTimePoint(Time time, Date date);
	void PrintTimePoint();
	inline uint32_t GetHours() {
		return m_time.hour;
	}
	inline uint32_t GetMin() {
		return m_time.minute;
	}
	bool operator > (TimePoint& rhs) {
		
		if (this->m_date.year > rhs.m_date.year) {
			return true;
		}
		else if (this->m_date.year == rhs.m_date.year) {
			if (this->m_date.month > rhs.m_date.month)
				return true;
			else if (this->m_date.month == rhs.m_date.month) {
				if (this->m_date.day > rhs.m_date.day)
					return true;
				else if (this->m_date.day == rhs.m_date.day) {
					return this->m_time > rhs.m_time;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	
	}
	bool operator < (TimePoint& rhs) {
		return rhs > *this;
	}
	bool operator >= (TimePoint& rhs) {
		return !(*this < rhs);
	}
	bool operator <= (TimePoint& rhs) {
		return !(*this > rhs);
	}
	bool operator == (TimePoint& rhs) {
		return (!(*this < rhs) && *this < rhs);
	}

public:
	static TimePoint GetUserTimePoint();

public:
	TimeDuration operator - (TimePoint& rightHandSide);

private:
	Date m_date;
	Time m_time;
	

};

