#pragma once
#include "Common.h"
#include "TimeTable.h"

class User
{
public:
	User(std::string name);
	const std::string* GetName();
private:

	bool AddEvent(Event& event);
	bool RemoveEvent(TimePoint& timpoint);


	const std::string m_name;

};

