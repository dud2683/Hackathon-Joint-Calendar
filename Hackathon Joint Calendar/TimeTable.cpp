#include "TimeTable.h"

void TimeTable::AddEvent()
{
	
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
