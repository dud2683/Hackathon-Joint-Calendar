#include "TimeTable.h"

void TimeTable::AddEvent(TimePoint& ct)
{
	bool valid = false;
	Event* m_event = nullptr;
	while (!valid) {
		Event::EventParams ep = Event::EventParams(ct);

		m_event = new Event(ep);
		if (FindEvent(ep.startTime) != -1) {
			COUT("You already have an event starting at that time.\nPlease create a new event.\n");
			valid = false;
		}
		else {
			valid = true;
		}
	}
	m_events.push_back(m_event);
	COUT("You have successfuly created an event :\n");
	m_event->PrintEvent();
}

void TimeTable::RemoveEvent(TimePoint& tp)
{
	int index = FindEvent(tp);
	if (index == -1) 
		COUT("There is no event at that time.");
	else {
		RemoveEvent(index, true);
	}
}

void TimeTable::RemoveEvent(int index, bool print)
{
	Event* selectedEV = m_events[index];
	
	if (print == true) {
		COUT("Removing \n");
		m_events[index]->PrintEventStart();
	}
	delete selectedEV;
	auto last = m_events.end() - 1;
	m_events[index] = *last;
	m_events.pop_back();
	if (m_events.size() >= 2) {
		Sort();
	}
}

void TimeTable::PrintNextThreeEvents()
{
	int size = m_events.size();
	bool sizeTest = (size > 0);
	bool lessThanThree = (size < 3);

	if (!sizeTest) {
		COUT("You do not have any events planned.\n");
		SLEEP(1);
	}
	else if (lessThanThree) {
		
		COUT("Your next event is\n");
		m_events[0]->PrintEvent();
		SLEEP(1);
		if (size == 2) {
			COUT("Your next event after that is\n");
			m_events[1]->PrintEvent();
			SLEEP(1);
		}
		
	}
	else {
		COUT("Your next three events are\n");
		m_events[0]->PrintEvent();
		SLEEP(1);
		COUT("Followed by\n");
		m_events[1]->PrintEvent();
		SLEEP(1);
		COUT("Followed by\n");
		m_events[2]->PrintEvent();
		SLEEP(1);
	}
}

void TimeTable::Update(TimePoint& ct)
{
	RemovePastEvents(ct);
	Sort();
	
}

int TimeTable::FindEvent(TimePoint& tp)
{
	int size = m_events.size();
	for (int i = 0;i < size;i++) {
		if (m_events[i]->GetStartPoint() == tp) {
			return i;
		}
	}
	return -1;

}

void TimeTable::RemovePastEvents(TimePoint& ct)
{
	for (int i = 0;i < m_events.size();i++) {
		if (m_events[i]->GetEndPoint() < ct) {
			RemoveEvent(i);
		}
	}
}
