#include "User.h"


User::User(std::string name) :
	m_name(name)
{
}

const std::string* User::GetName()
{
	return &m_name;
}

bool User::AddEvent()
{
	return true;
}

bool User::RemoveEvent()
{
	return false;
}

bool User::AddEvent(Event& event)
{
	return false;
}

bool User::RemoveEvent(TimePoint& timpoint)
{
	return false;
}


