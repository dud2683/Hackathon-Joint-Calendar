#pragma once
#include "Common.h"
#include "TimeTable.h"

class User
{
public:
	User(std::string name);
	const std::string* GetName();
	void AddEvent();
	void RemoveEvent();
	void CheckCalendar();
private:

	void AddEvent(Event& event);
	void RemoveEvent(TimePoint& timpoint);
	
	TimeTable m_timeTable;
	const std::string m_name;

};

