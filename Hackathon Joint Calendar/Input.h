#pragma once

class Input
{
public:
	enum class UserSelectOptions {
		Select=1,
		Create=2,
		Leave=3
	};
	enum class UpdateOptions {
		CheckMyCalendar=1,
		AddEvent=2,
		RemoveEvent=3,
		FindTimeForEvent=4,
		LogOut=5
	};

	static UserSelectOptions PollUserSelection();
	static UpdateOptions PollUpdateOptions();
	static bool UserNameInUse();
	static bool YesOrNo();
	static int GetInt();
	static std::string GetString();
	static std::vector<int> GetTime();
	static std::vector<int> GetDate();

};

