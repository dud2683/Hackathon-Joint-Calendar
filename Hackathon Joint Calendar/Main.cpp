#include "Calendar.h"

int main() {


	Calendar c;
	while (true) {
		c.UserSelect();
		while (true) {
			c.Update();
		}
	}

	system("pause");
	return 0;
}