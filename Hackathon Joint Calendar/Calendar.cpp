#include "Calendar.h"

Calendar::Calendar()
{
	COUT("Running\n");
	UpdateTime();
	p_selectedUser = nullptr;
	COUT("The current time is ");
	CT.PrintTimePoint();
	SLEEP(2);
}

void Calendar::UserSelect(bool* loop, bool* loop2)
{
	std::string user;
	switch (Input::PollUserSelection()) {
		typedef Input::UserSelectOptions u;
	case u::Create:
		CreateUser();
		break;
	case u::Select:
		COUT("Please input a username ");
		user = Input::GetString();
		SelectUser(user);
		SLEEP(1);
		break;
	case u::Leave :
		COUT("Goodbye\n");
		SLEEP(2);
		*loop = false;
		*loop2 = false;
		break;
	}
}

void Calendar::Update(bool* loop)
{
	UpdateTime();
	auto input = Input::PollUpdateOptions();

	switch (input) {
		typedef Input::UpdateOptions u;
	case u::AddEvent:
		p_selectedUser->AddEvent();
		break;

	case u::RemoveEvent:
		p_selectedUser->RemoveEvent();
		break;
	
	case u::FindTimeForEvent:
		FindTimeForEvent();

	case u::CheckMyCalendar:
		p_selectedUser->CheckCalendar(CT);
		break;
	
	case u::LogOut:
		COUT("Logging out.\n");
		p_selectedUser = nullptr;
		*loop = false;
		break;
	}
	
}

void Calendar::UpdateTime()
{

	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	
	CT = ConvertStringToTP(buf);
	
}
void Calendar::CreateUser()
{
	COUT("Please enter a username: ");
	std::string username = Input::GetString();
	auto user = FindUser(username);
	if (user != nullptr) {
		if (Input::UserNameInUse()) {
			SelectUser(user);
		}
		else {
			COUT("Please try another username.\n");
			CreateUser();
		}
	}
	else {
		User u = User(username);
		m_users.push_back(u);
		SelectUser(*u.GetName());
	}

}

void Calendar::CreateUser(std::string name)
{
	m_users.push_back(User(name));
	COUT("User created successfuly\n");
	SelectUser(name);
}

void Calendar::SelectUser(User* user)
{
	
	p_selectedUser = user;
	COUT("Welcome "<<*user->GetName()<<"\n");
	user->UpdateTimeTable(CT);
}

void Calendar::SelectUser(std::string name)
{
	auto user = FindUser(name);
	if (user == nullptr) {
		COUT("That user does not exist, would you like to create a user with that name?\n");
		bool answer = Input::YesOrNo();
			if (answer) {
				CreateUser(name);
			}
			else {
				COUT("Please try another name.\n");
				auto s = Input::GetString();
				SelectUser(s);
			}
	}
	else {
		SelectUser(user);
	}
}

User* Calendar::FindUser(std::string name)
{
	int size = m_users.size();
	for (int i = 0;i < size;i++) {
		if (*m_users[i].GetName() == name) {
			return &m_users[i];
		}
	}
	return nullptr;
}

void Calendar::FindTimeForEvent()
{
}

TimePoint Calendar::ConvertStringToTP(std::string s)
{
		
	auto str = s.c_str();
	std::vector<int> ans;
	int t = 0;
	do
	{
		const char* begin = str;

		while (!(*str == '-'||*str=='.' )&& *str)
			str++;

		ans.push_back(stoi(std::string(begin, str)));
		t++;
		str++;
	} while (t<3);

	

	int year = ans[0];
	auto month = Date::Month(ans[1]);
	int day = ans[2];
	std::vector<int> hms;
	do
	{
		const char* begin = str;

		while (*str != ':' && *str)
			str++;

		hms.push_back(std::stoi(std::string(begin, str)));
	} while (0 != *str++);

	int hours = hms[0];
	int min = hms[1];
	

	return TimePoint(Time(min,hours),Date(day,month,year));
}

