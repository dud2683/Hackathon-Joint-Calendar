#include "Calendar.h"

Calendar::Calendar()
{
	COUT("running\n");
	p_selectedUser = nullptr;
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
		p_selectedUser->CheckCalendar();
		break;
	
	case u::LogOut:
		p_selectedUser = nullptr;
		*loop = false;
		break;
	}
	
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

