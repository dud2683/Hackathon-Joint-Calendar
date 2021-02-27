#include "TimePoint.h"

TimePoint TimePoint::operator-(TimePoint& leftHandSide)
{
    return TimePoint();
}

bool TimePoint::Date::ValidateDate(uint32_t day, Month month)
{
    return false;
}



TimePoint::Date TimePoint::Date::CreateDate(uint32_t day, Month month)
{
    if (ValidateDate(day, month))
        return TimePoint::Date(day, month);
    else
        return TimePoint::Date(0, TimePoint::Date::Month::Invalid);
   
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
        return Time(-1, -1);
}
