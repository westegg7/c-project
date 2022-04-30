#include <stdio.h>
#include "18-2.human.h"

int main() {
	struct Human Han = Create_Human("Han", 31, MALE);

	Print_Human(&Han);

	return 0;
}
