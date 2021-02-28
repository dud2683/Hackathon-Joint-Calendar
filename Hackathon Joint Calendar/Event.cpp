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
    m_endTimePoint.PrintTimePointTime();
    
}

void Event::PrintEventStart()
{
    COUT(m_name << " at ");
    m_startTimePoint.PrintTimePoint();
}

TimePoint& Event::GetEndPoint()
{
    return m_endTimePoint;
}

TimePoint& Event::GetStartPoint()
{
    return m_startTimePoint;
}

Event::EventParams::EventParams(TimePoint& ct)
{
    COUT("What would you like to call this event?\n");
    std::string ans = Input::GetString();
    eventName = ans;
    type = EventType::Personal;       
    bool valid = false;
    bool valid1 = false;
    
    TimePoint tp;
    do {
        do {
            COUT("Start point:\n");
            tp = TimePoint::GetUserTimePoint();
            this->startTime = tp;
            if (tp > ct)
                valid = true;
            else
                COUT("You cannot add a start point in the past,\n");

        } while (!valid);
        COUT("End point:\n");
        auto etp = TimePoint::GetUserTimePointTime(tp.GetDate());
        if (etp > tp) {
            this->endTime = etp;
            valid1 = true;
        }
        else {
            valid1 = false;
            COUT("Your end time must be after your start time.\n");
        }
        
    } while (!valid1);
          

}
