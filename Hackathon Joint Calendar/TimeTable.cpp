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
	
}

void TimeTable::PrintNextThreeEvents()
{
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
