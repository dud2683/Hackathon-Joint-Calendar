#pragma once
#include "Common.h"
class Calendar
{

public:
	Calendar() = delete;
	~Calendar();
	static void CreateCalendar();
private:
	void Run();
};

