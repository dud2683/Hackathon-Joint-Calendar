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
	
}

void User::CheckCalendar()
{
	m_timeTable.PrintNextThreeEvents();
}

void User::AddEvent(Event& event)
{
	
	
}

void User::RemoveEvent(TimePoint& timpoint)
{
	
}


