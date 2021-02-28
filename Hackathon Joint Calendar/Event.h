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
		EventParams(TimePoint& ct);
		TimePoint startTime;
		TimePoint endTime;
		std::string eventName;
		EventType type;
	};
	Event(EventParams& ep);

	
	void PrintEvent();
	void PrintEventStart();
	TimePoint& GetEndPoint();
	TimePoint& GetStartPoint();
private:
	
	TimePoint m_startTimePoint;
	TimePoint m_endTimePoint;
	std::string m_name;

	TimeDuration m_duration;
	EventType m_eventType;

	
};

