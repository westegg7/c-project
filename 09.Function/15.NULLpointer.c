#include <stdio.h>

int main()
{
	// int *ptr = 1234;	//Runtime error 발생! 주소를 잘못 넣었을때 발생.

	// printf("%p\n", ptr);
	// printf("%d\n", *ptr);

	int* safer_ptr = NULL;	//NULL값을 대입하는 이유는 이 포인터를 사용할지 안할지 판단하기 위함.

	int a = 123;

	int b;
	scanf("%d", &b);

	if (b % 2 == 0)	//b가 0이면 a의 주소값을 포인터에 대입. b가 0이 아니라면 포인터는 NULL 값
		safer_ptr = &a;

	if (safer_ptr != NULL)	//이런 식으로 판단에 사용.
		printf("%p\n", safer_ptr);

	if (safer_ptr != NULL)
		printf("%d\n", *safer_ptr);


	return 0;
}
