#include "TimePoint.h"

TimePoint::TimePoint(Time time, Date date)
    :
    m_time(time),
    m_date(date)
{
}

TimePoint TimePoint::CreateTimePoint(Time time, Date date)
{
    return TimePoint(time, date);
}

void TimePoint::PrintTimePoint()
{
    m_time.PrintTime();
    m_date.PrintDate();
}

TimeDuration TimePoint::operator-(TimePoint& rightHandSide)
{
    assert(this->m_time.hour >= rightHandSide.m_time.hour);
    uint32_t min, hour;

    hour = this->m_time.hour - rightHandSide.m_time.hour;

    if (rightHandSide.m_time.minute <= this->m_time.minute)
        min = this->m_time.minute - rightHandSide.m_time.minute;
    else {
        min = rightHandSide.m_time.minute - this->m_time.minute;
        hour--;
    }
    return TimeDuration(hour,min);
}

void Date::PrintMonth()
{
    typedef Date::Month Month;
    switch (month) {
    case Month::January:
            COUT("January ");
            break;
    case Month::February:
        COUT("February ");
        break;
    case Month::March:
        COUT("March ");
        break;
    case Month::April:
        COUT("April ");
        break;
    case Month::June:
        COUT("June ");
        break;
    case Month::July:
        COUT("July ");
        break;
    case Month::August:
        COUT("August ");
        break;
    case Month::September:
        COUT("September ");
        break;
    case Month::October:
        COUT("October ");
        break;
    case Month::November:
        COUT("November ");
        break;
    case Month::December:
        COUT("December ");
        break;

    }
}

bool Date::ValidateDate(uint32_t day, Month month, uint32_t year)
{
    typedef Date::Month Month;

    if (year < 2000 || year>2200)
        return false;

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0);

    bool returnBool = false;

    switch (month){
    case Month::January:
        if (day <= 31)
            returnBool = true;
        break;
    case Month::February:
       
        if (isLeapYear) {
            if(day<=29)
                returnBool = true;
        }
        else {
            if (day <= 28)
                returnBool = true;
        }
        break;
    case Month::March:
        if (day <= 31)
            returnBool = true;
        break;
    case Month::April:
        if (day <= 30)
            returnBool = true;
        break;
    case Month::May:
        if (day <= 31)
            returnBool = true;
        break;
    case Month::June:
        if (day <= 30)
            returnBool = true;
        break;
    case Month::July:
        if (day <= 31)
            returnBool = true;
        break;
    case Month::August:
            if (day <= 31)
                returnBool = true;
            break;
    case Month::September:
        if (day <= 30)
            returnBool = true;
        break;
    case Month::October:
        if (day <= 31)
            returnBool = true;
        break;
    case Month::November:
        if (day <= 30)
            returnBool = true;
        break;
    case Month::December:
        if (day <= 31)
            returnBool = true;
        break;
            
    }
    if (!returnBool) {
        COUT("That date was invalid, please try again.\n");
    }
    return returnBool;
}


Date Date::CreateDate(uint32_t day, Month month, uint32_t year)
{
   
     return Date(day, month, year);
   
}

void Date::PrintDate()
{
    PrintMonth();
    COUT(day << ", " << year<<".\n");
}

bool Time::ValidateTime(uint32_t minute, uint32_t hour)
{
    if (minute < 60 && hour < 24)
        return true;
    else {
        COUT("That time is invalid, please try again.\n");
        return false;
    }
}

Time Time::CreateTime(uint32_t minute, uint32_t hour)
{
   return Time(minute, hour);
}

void Time::PrintTime()
{
    if (minute >= 10)
        COUT(hour << ":" << minute << " on ");
    else
        COUT(hour << ":0" << minute << " on ");
}
