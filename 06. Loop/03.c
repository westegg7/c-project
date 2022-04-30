#include <stdio.h>

int main()
{
	int i = 10;

	while(i)
	{
		printf("%d is true\n", i--); //후위 감소연산자!!
	}
	printf("%d is false\n", i); // 0 이 가지는 값은 false!! 0이외에는 모두 True!!

	return 0;
}
