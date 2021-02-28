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
	void UpdateTime();
	void CreateUser();
	void CreateUser(std::string);
	void SelectUser(User* user);
	void SelectUser(std::string);
	User* FindUser(std::string name);

	void FindTimeForEvent();
	TimePoint ConvertStringToTP(std::string s);

private:
	User* p_selectedUser=nullptr;
	TimePoint CT;
	std::vector<User> m_users;
};

