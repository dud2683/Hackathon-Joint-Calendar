#include "Event.h"

bool Event::operator>(Event rhs)
{
    return this->m_startTimePoint>rhs.m_startTimePoint;
}

bool Event::operator<(Event rhs)
{
    return rhs.m_startTimePoint>this->m_startTimePoint;
}

bool Event::operator>=(Event rhs)
{
    return !(rhs.m_startTimePoint > this->m_startTimePoint);
}

bool Event::operator<=(Event rhs)
{
    return !(this->m_startTimePoint > rhs.m_startTimePoint);
}



Event::Event(EventParams& ep) 
    :
    m_startTimePoint(ep.startTime),
    m_endTimePoint(ep.endTime),
    m_duration(m_endTimePoint - m_startTimePoint),
    m_eventType(ep.type),
    m_name(ep.eventName)

{
}

void Event::PrintEvent()
{
    COUT(m_name << " at ");
    m_startTimePoint.PrintTimePoint();
    COUT("It goes till ");
    m_endTimePoint.PrintTimePoint();
    
}

Event::EventParams::EventParams()
{
    COUT("What would you like to call this event?\n");
    std::string ans = Input::GetString();
    eventName = ans;
    type = EventType::Personal;
    {
       
        Time* time;
        do {
            COUT("Start point:\n");
            COUT("Please input the time (hh:mm)(24h)\n");
            auto ans = Input::GetTime();

            Time t = Time::CreateTime(ans[1], ans[0]);
            time = new Time(t);
        } while (!Time::ValidateTime(time->minute, time->hour));

        Date d;
        do {
            COUT("Please input the date (mm/dd/yyyy)\n");
            auto ans = Input::GetDate();
            d.month = Date::Month(ans[0]);
            d.day = ans[1];
            d.year = ans[2];

        } while (!Date::ValidateDate(d.day, d.month, d.year));

        this->startTime = TimePoint(*time, d);
        delete time;
    }
    {
        Time* time;
        do {
            COUT("End point:\n");
            COUT("Please input the time (hh:mm)(24h)\n");
            auto ans = Input::GetTime();

            Time t = Time::CreateTime(ans[1], ans[0]);
            time = new Time(t);
        } while (!Time::ValidateTime(time->minute, time->hour));


        Date d;
        do {

            COUT("Please input the date (mm/dd/yyyy)\n");
            auto ans = Input::GetDate();
            d.month = Date::Month(ans[0]);
            d.day = ans[1];
            d.year = ans[2];
        } while (!Date::ValidateDate(d.day, d.month, d.year));

        this->endTime = TimePoint(*time, d);
        delete time;
    }

}
