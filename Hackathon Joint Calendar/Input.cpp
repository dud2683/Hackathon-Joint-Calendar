
#include "Common.h"
#include "TimePoint.h"

std::string d;

std::string prompt1 = 
R"(Would you like to
	Select a user (1),
	Create a user (2) or
	Leave (3)?
)";
std::string prompt2 =
R"(Would you like to
	Check your calendar for your next 3 events (1)
	Add an event to your calendar (2),
	Remove an existing event from your calendar (3) or
	Logout (4)
)";
std::string prompt3 =
R"(That username is already in use, would you like to
	Login as that user (1) or 
	Create a new user with a differernt name (2)?
)";

Input::UserSelectOptions Input::PollUserSelection()
{
	COUT(prompt1);
	int answer;
	std::string rough;
	
	std::cin.sync();
	std::getline(std::cin,rough);
	answer = rough[0]-48;
	//COUT(answer);// To troubleshoot, remove //
	if(answer < 1 ||answer>3) {
		INVALID_INPUT;
		return PollUserSelection();

	}else{
		return UserSelectOptions(answer);
	}
	
	
	
		
}

Input::UpdateOptions Input::PollUpdateOptions()
{
	
	COUT(prompt2);
	std::string rough;
	std::cin.sync();
	std::getline(std::cin, rough);
	int answer = rough[0]-48;

	if (answer < 1 || answer>4) {
		INVALID_INPUT;
		return PollUpdateOptions();
	}
	else {
		return UpdateOptions(answer);
	}
		
		
	
}

bool Input::UserNameInUse()
{
	COUT(prompt3);
	std::string rough;
	std::cin.sync();
	std::getline(std::cin, rough);
	int answer = rough[0] - 48;
	if (answer == 1)
		return true;
	else
		return false;
}

bool Input::YesOrNo()
{
	YES_NO;
	std::string rough;
	std::cin.sync();
	std::getline(std::cin, rough);
	int answer = rough[0] - 48;
	if (answer == 1)
		return true;
	else
		return false;
}

int Input::GetInt()
{
	std::string x;
	std::cin.sync();
	std::getline(std::cin, x);
	return std::stoi(x);
}

std::string Input::GetString()
{
	std::string answer;
	std::cin.sync();
	std::getline(std::cin, answer);
	return answer;
}

std::vector<int> Input::GetTime()
{
	bool thereIsFail = false;
	std::string raw;
	std::cin.sync();
	
	std::getline(std::cin, raw);
	std::vector<int> ans;

	auto str = raw.c_str();

	do
	{
		const char* begin = str;

		while (*str != ':' && *str)
			str++;
		std::string sti = std::string(begin, str);
		if(VerifyNumber(sti))
			ans.push_back(std::stoi(sti));
		else {
			INVALID_INPUT;
			return GetTime();
		}
	} while (0 != *str++);

	if (ans.size() != 2) {
		INVALID_INPUT;
		return GetTime();
	}
	return ans;
}

std::vector<int> Input::GetDate()
{
	//mm/dd/yyyy
	std::string raw;
	std::string copy;
	std::cin.sync();
	std::getline(std::cin, raw);
	copy = raw;
	std::vector<int> ans;

	
	
	auto str = raw.c_str();

	do
	{
		const char* begin = str;

		while (*str != '/' && *str)
			str++;
		std::string sti = std::string(begin, str);
		if(VerifyNumber(sti))
			ans.push_back(std::stoi(sti));
		else {
			INVALID_INPUT;
			return GetDate();
		}
	} while (0 != *str++);

	if (ans.size() != 3) {
		INVALID_INPUT;
		return GetDate();
	}
	
	return ans;
}

bool Input::VerifyNumber(std::string& s)
{
	
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
	
}


