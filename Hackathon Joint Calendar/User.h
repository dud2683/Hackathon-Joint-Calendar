#pragma once
#include "Common.h"
#include "TimeTable.h"

class User
{
	bool AddEvent(Event& event);
	bool RemoveEvent(TimePoint& timpoint);
	
	std::string SetUserName(User& Name);
	std::string Name;

};

