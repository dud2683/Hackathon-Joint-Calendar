#pragma once
#include "Common.h"
#include "TimeTable.h"

class User
{
	bool AddEvent(Event& event);
	bool RemoveEvent(TimePoint& timpoint);
	
private:
	std::string m_name;
	void SetUserName(std::string& m_name);
public:
	
	
	

};

