#include "Calendar.h"
#include <ctime>

int main() {
	
	
	COUT("");

	Calendar c;
	bool us = true, ud = true;
	while (us) {
		us = true, ud = true;
		c.UserSelect(&us, &ud);
		while (ud) {
			c.Update(&ud);
		}
	}


	return 0;
}