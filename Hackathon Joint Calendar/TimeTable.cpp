#include "TimeTable.h"

void TimeTable::AddEvent()
{
	Event::EventParams ep;
	
	Event* m_event = new Event(ep);
	m_events.push_back(m_event);
	COUT("You have successfuly created an event :\n");
	m_event->PrintEvent();
}

void TimeTable::RemoveEvent(TimePoint tp)
{
	int index = FindEvent(tp);
	if (index == -1) 
		COUT("There is no event at that time.");
	else {
		Event* selectedEV = m_events[index];
		delete selectedEV;
		auto last = m_events.end()-1;
		m_events[index] = *last;
		m_events.pop_back();
		Sort();
	}
		
	
}

void TimeTable::PrintNextThreeEvents()
{
	RemovePastEvents();
	int size = m_events.size();
	bool sizeTest = (size > 0);
	bool lessThanThree = (size < 3);

	if (!sizeTest) {
		COUT("You do not have any events planned.\n");
	}
	else if (lessThanThree) {
		
		COUT("Your next event is\n");
		m_events[0]->PrintEvent();
		if (size == 2) {
			COUT("Your next event after that is\n");
			m_events[1]->PrintEvent();
		}
		
	}
	else {
		COUT("Your next three events are\n");
		m_events[0]->PrintEvent();
		COUT("Followed by\n");
		m_events[1]->PrintEvent();
		COUT("Followed by\n");
		m_events[2]->PrintEvent();
		
	}
}

int TimeTable::FindEvent(TimePoint& tp)
{
	return 0;
}

void TimeTable::RemovePastEvents()
{
}
