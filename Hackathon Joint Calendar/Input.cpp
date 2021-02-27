
#include "Common.h"

std::string prompt1 = 
R"(Would you like to
	Select a user (1),
	Create a user (2) or
	Leave (3)?)";
std::string prompt2 =
R"(Would you like to
	Check your calendar for your next meeting (1)
	Add an event to your calendar(2),
	Remove an existing event from your calendar (3),
	Find a time for an event (4) or
	Logout (5))";
Input::UserSelectOptions Input::PollUserSelection()
{
	COUT(prompt1);
	int answer;
	CIN(answer);
	if (answer < 1 || answer>3) {
		INVALID_INPUT;
		return PollUserSelection();
	}
	else
		return UserSelectOptions(answer);
}

Input::UpdateOptions Input::PollUpdateOptions()
{
	
	COUT(prompt2);
	int answer;
	CIN(answer);
	if (answer < 1 || answer>5) {
		INVALID_INPUT;
		return PollUpdateOptions();
	}
	else
		return UpdateOptions(answer);
	
}
