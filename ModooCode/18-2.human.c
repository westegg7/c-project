#include <stdio.h>
#include <string.h>
#include "18-2.human.h"

struct Human Create_Human(char *name, int age, int gender) {
	struct Human human;

	human.age = age;
	human.gender = gender;
	strcpy(human.name, name);

	return human;
}

int Print_Human(*human) {
	printf("Age : %d \n", human->age);
	printf("Name : %s \n", human->name);
	if (human->gender == MALE) {
		printf("Gender : MALE\n");
	} else if (human->gender == FEMALE) {
		printf("Gender : FEMALE\n");
	}
}
