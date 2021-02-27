#pragma once
#include "Common.h"
#include "User.h"
class Calendar
{

public:
	Calendar();
	void UserSelect(bool* loop, bool* loop2);
	void Update(bool* loop);
private:
	User* CreateUser();
	void SelectUser(User* user);
	void SelectUser(std::string);
	User* FindUser(std::string name);

	

private:
	User* p_selectedUser=nullptr;
	
	std::vector<User> m_users;
};

