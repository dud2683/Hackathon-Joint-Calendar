#include "User.h"


void User::SetUserName(std::string& name)
{
	std::string placeHolder="test";//placeHolder for the string from Input.GetString
	std::string what;
	COUT("Please enter your name:\n");
	//Input.GetString gets the string at the console
	name = placeHolder;
}
