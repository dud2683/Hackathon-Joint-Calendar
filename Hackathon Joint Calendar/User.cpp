#include "User.h"


User::User(std::string name) :
	m_name(name)
{
}

const std::string* User::GetName()
{
	return &m_name;
}

std::string User::SetUserName(User& Name)
{
	COUT("Please enter your name:");
	CIN(m_name);
	return std::string();
}
