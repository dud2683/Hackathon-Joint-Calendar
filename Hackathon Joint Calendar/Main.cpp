#include "Calendar.h"

int main() {


	Calendar c;
	bool us = true, ud = true;
	while (us) {
		c.UserSelect(&us, &ud);
		while (ud) {
			c.Update(&ud);
		}
	}


	return 0;
}