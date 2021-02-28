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
	static void CreateEvent(EventParams& eventParameters, Event* p_event);
	void PrintEvent();
private:
	Event(EventParams& ep);
	TimePoint m_timePoint;
	std::string m_name;
	TimeDuration m_duration;
	EventType m_eventType;

	
};

