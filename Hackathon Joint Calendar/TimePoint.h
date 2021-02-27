#pragma once
#include "Common.h"
class TimePoint
{
public:
	void PrintTimePoint();
private:
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

	public:

		void PrintMonth();

	private:

		Date(uint32_t day, Month month, uint32_t year) {
			this->day = day;
			this->month = month;
			this->year = year;
		}
		bool ValidateDate(uint32_t day, Month month, uint32_t year);

	public:

		Date CreateDate(uint32_t day, Month month, uint32_t m_year);
		void PrintDate();
		uint32_t day;
		Month month;
		uint32_t year;
	};
	struct Time {
	private:

		Time(uint32_t minute, uint32_t hour) {
			this->minute = minute;
			this->hour = hour;
		}
		bool ValidateTime(uint32_t minute, uint32_t hour);
	public:
		Time CreateTime(uint32_t minute, uint32_t hour);
		void PrintTime();
		uint32_t minute;
		uint32_t hour;
	};

public:
	TimePoint operator - (TimePoint& leftHandSide);

private:
	Date m_date;
	Time m_time;
	

};

