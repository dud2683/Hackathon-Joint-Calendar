#pragma once
#include "Event.h"
#include "Common.h"
#include "TimePoint.h"
class TimeTable
{
public:
	
	void AddEvent();
	void RemoveEvent(TimePoint tp);
	void PrintNextThreeEvents();
private:
	void Sort() {
		std::sort(m_events.begin(), m_events.end(),
			[](Event* a, Event* b) {
				return *a > *b;
			});
	}
	int FindEvent(TimePoint& tp); //returns index of event
	void RemovePastEvents();

	std::vector<Event*> m_events;
};

