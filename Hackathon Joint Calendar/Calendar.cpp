#include "Calendar.h"

Calendar::Calendar()
{
	COUT("running\n");
	p_selectedUser = nullptr;
}

void Calendar::UserSelect(bool* loop, bool* loop2)
{
	switch (Input::PollUserSelection()) {
		typedef Input::UserSelectOptions u;
	case u::Create:
		p_selectedUser = CreateUser();
		break;
	case u::Select:
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
	Input::PollUpdateOptions();
	*loop = false;
}

User* Calendar::CreateUser()
{
	COUT("Please enter a username: ");
	std::string username = Input::GetString();
	auto user = FindUser(username);
	if (user != nullptr) {
		if (Input::UserNameInUse()) {
			SelectUser(user);
		}
		else {
			COUT("Your user has been succesfuly created!\n");
			return CreateUser();
		}
	}
	else {
		m_users.push_back(User(username));
	}

}

void Calendar::SelectUser(User* user)
{
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

