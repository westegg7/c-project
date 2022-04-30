#include <stdio.h>

int main()	// switch 경우의 수가 적은 경우엔 스위치케이스를 많이 쓴다. if문보다 보기에 간결하다.
{
	char c;

	while((c = getchar()) != '.')
	{
		printf("You love ");

		switch (c) // Note: integer types only
		{
		case 'a':
		case 'A':
			printf("apple");
			break;
		case 'b':
			printf("basketball");
			break;
		case 'c':
			printf("cup");
			break;
		default:
			printf("nothing");
		}

		printf(".\n");

		while (getchar() != '\n') // 줄바꿈이 나올 때까지 첫문자 이후는 무시하겠다. (줄바꿈 전까지는 이 while문 안을 계속 돈다.) 버퍼를 비운다는 개념!!!!!! 중요!!!!
			continue;
	}

	return 0;
}
