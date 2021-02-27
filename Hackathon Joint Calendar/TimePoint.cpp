#include "TimePoint.h"

void TimePoint::PrintTimePoint()
{
    m_time.PrintTime();
    m_date.PrintDate();
}

TimePoint TimePoint::operator-(TimePoint& leftHandSide)
{
    return TimePoint();
}

void TimePoint::Date::PrintMonth()
{
    typedef TimePoint::Date::Month Month;
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

bool TimePoint::Date::ValidateDate(uint32_t day, Month month, uint32_t year)
{
    typedef TimePoint::Date::Month Month;

    if (year < 2000 || year>2200)
        return false;

    bool returnBool = false;

    switch (month){
    case Month::January:
        if (day <= 31)
            returnBool = true;
        break;
    case Month::February:
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0);
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
    return returnBool;
}


TimePoint::Date TimePoint::Date::CreateDate(uint32_t day, Month month, uint32_t year)
{
    if (ValidateDate(day, month, year))
        return TimePoint::Date(day, month, year);
    else
        return TimePoint::Date(0, TimePoint::Date::Month::Invalid, 0);
   
}

void TimePoint::Date::PrintDate()
{
    PrintMonth();
    COUT(" " << day << ", " << year);
}

bool TimePoint::Time::ValidateTime(uint32_t minute, uint32_t hour)
{
    if (minute < 60 && hour < 24)
        return true;
    else
        return false;
}

TimePoint::Time TimePoint::Time::CreateTime(uint32_t minute, uint32_t hour)
{
    if (ValidateTime(minute, hour))
        return Time(minute, hour);
    else
        return Time(61, 25);
}

void TimePoint::Time::PrintTime()
{
    COUT(hour << ":" << minute << ", ");
}
