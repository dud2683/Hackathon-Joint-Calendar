#pragma once
#include "Event.h"
#include "Common.h"
#include "TimePoint.h"
class TimeTable
{
public:
	
	void AddEvent(TimePoint& ct);
	void RemoveEvent(TimePoint& tp);
	void RemoveEvent(int index, bool print=false);
	void PrintNextThreeEvents();
	void Update(TimePoint& ct);
	std::vector<Event*> m_events;
private:
	void Sort() {
		std::sort(m_events.begin(), m_events.end(),
			[](Event* a, Event* b) {
				return *a < *b;
			});
	}
	int FindEvent(TimePoint& tp); //returns index of event
	void RemovePastEvents(TimePoint& ct);

	
};

