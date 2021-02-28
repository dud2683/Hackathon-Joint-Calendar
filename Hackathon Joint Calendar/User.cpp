#include "User.h"


User::User(std::string name) :
	m_name(name)
{
}

const std::string* User::GetName()
{
	return &m_name;
}

void User::AddEvent()
{
	m_timeTable.AddEvent();
}

void User::RemoveEvent()
{
	TimePoint tp = TimePoint::GetUserTimePoint();
	
	RemoveEvent(tp);
}

void User::CheckCalendar(TimePoint& ct)
{
	m_timeTable.Update(ct);
	m_timeTable.PrintNextThreeEvents();
}

void User::UpdateTimeTable(TimePoint& ct)
{
	m_timeTable.Update(ct);
}

bool User::FindEvent(TimePoint& startTime)
{
    int size = m_timeTable.m_events.size();
    for (int i = 0;i < size;i++) {
        if (m_timeTable.m_events[i]->GetStartPoint() == startTime)
            return true;
    }
    return false;
}

void User::AddEvent(Event& event)
{
	
	
}

void User::RemoveEvent(TimePoint& timepoint)
{
    m_timeTable.RemoveEvent(timepoint);
}


