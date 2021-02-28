#pragma once
#include "Common.h"
#include "TimeTable.h"

class User
{
public:
	User(std::string name);
	const std::string* GetName();
	void AddEvent(TimePoint& ct);
	void RemoveEvent();
	void CheckCalendar(TimePoint& ct);
	void UpdateTimeTable(TimePoint& ct);
	bool FindEvent(TimePoint& tp);
private:
	
	void AddEvent(Event& event);
	void RemoveEvent(TimePoint& timepoint);
	
	TimeTable m_timeTable;
	const std::string m_name;

};

