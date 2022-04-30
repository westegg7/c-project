#include <stdio.h>

int main()
{
	int count = 0;

	while (1)
	{
		printf("Current count is %d. Continue? (y/n)\n", count);

		int c = getchar(); // if문에는 함수가 올 수 없는듯??

		if (c == 'n')
			break;
		else if (c == 'y')
			count++;
		else
			printf("Please input y or n\n");

		while (getchar() != '\n')	// 중요!!  -- 같은 코드가 중복. 하나로 합치자.
			continue;	// 첫입력 이외의 문자는 줄바꿈이 나올때까지 무시한다.
	}


	return 0;
}
