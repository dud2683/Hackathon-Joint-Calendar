#include "Calendar.h"

Calendar::Calendar()
{
	COUT("running");
}

void Calendar::UserSelect()
{
	switch (Input::PollUserSelection()) {
		typedef Input::UserSelectOptions u;
	case u::Create:
		p_selectedUser = CreateUser();
		break;
	case u::Select:
	

	}
}

void Calendar::Update()
{
}

User* Calendar::CreateUser()
{
	return nullptr;
}

void Calendar::SelectUser(User*)
{
}

User* Calendar::FindUser(std::string name)
{
	return nullptr;
}

