#include "User.h"


std::string User::SetUserName(User& Name)
{
	COUT("Please enter your name:");
	CIN(Name);
	return std::string();
}
