#pragma once
#include "Common.h"
#include "User.h"
class Calendar
{

public:
	Calendar();
	void UserSelect();
	void Update();
private:
	User* CreateUser();
	void SelectUser(User*);
	User* FindUser(std::string name);

	

private:
	User* p_selectedUser;
	
	std::vector<User> m_users;
};

