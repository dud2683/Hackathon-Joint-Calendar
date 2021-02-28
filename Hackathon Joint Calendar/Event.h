#pragma once
#include "Common.h"
#include "TimePoint.h"
class Event
{
public:
	bool operator> (Event rhs);
	bool operator< (Event rhs);
	bool operator>= (Event rhs);
	bool operator<= (Event rhs);
	enum class EventType {
		Meeting,
		FreeTime,
		Break,
		Personal
	};
	struct EventParams {
		EventParams() = default;
		TimePoint startTime;
		int duration;
		std::string eventName;
		EventType type;
	};
	
	void PrintEvent();
private:
	
	TimePoint m_timePoint;
	std::string m_name;
	TimeDuration m_duration;
	EventType m_eventType;

	
};

