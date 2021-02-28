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

TimePoint& Event::GetEndPoint()
{
    return m_endTimePoint;
}

TimePoint& Event::GetStartPoint()
{
    return m_startTimePoint;
}

Event::EventParams::EventParams()
{
    COUT("What would you like to call this event?\n");
    std::string ans = Input::GetString();
    eventName = ans;
    type = EventType::Personal;       
    
    COUT("Start point:\n");
    this->startTime = TimePoint::GetUserTimePoint();
    COUT("End point:\n");
    this->endTime = TimePoint::GetUserTimePoint();
          

}
