#include "Event.h"

bool Event::operator>(Event rhs)
{
    return this->m_timePoint>rhs.m_timePoint;
}

bool Event::operator<(Event rhs)
{
    return rhs.m_timePoint>this->m_timePoint;
}

bool Event::operator>=(Event rhs)
{
    return !(rhs.m_timePoint > this->m_timePoint);
}

bool Event::operator<=(Event rhs)
{
    return !(this->m_timePoint > rhs.m_timePoint);
}

/*void Event::CreateEvent(EventParams& eventParameters, Event* p_event)
{
    p_event = new Event(eventParameters);
}*/

void Event::PrintEvent()
{
    COUT(m_name << " at ");
    m_timePoint.PrintTimePoint();
    COUT("It goes till " << m_timePoint.GetHours() << ":" << m_timePoint.GetMin() << ".\n");
}
