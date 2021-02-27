#pragma once
#include "Common.h"
#include "User.h"
class Calendar
{

public:
	Calendar() = delete;
	~Calendar();
	static void CreateCalendar();
private:
	void Run();

private:
	std::vector<User> s_users;
};

