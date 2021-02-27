#include "User.h"


User::User(std::string name) :
	m_name(name)
{
}

const std::string* User::GetName()
{
	return &m_name;
}

