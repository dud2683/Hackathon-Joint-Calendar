#pragma once
#include "Common.h"
#include "TimePoint.h"
class Event
{
public:
	enum class EventType {
		Meeting,
		FreeTime,
		Break,
		Personal
	};
	struct EventParams {
		
		TimePoint startTime;
		int duration;
		std::string eventName;
		EventType type;
	};
	bool CreateEvent(EventParams& eventParameters, Event*& p_event);
private:
	TimePoint m_timePoint;
	std::string m_name;
	TimeDuration m_duration;
	EventType m_eventType;

	
};

