/* 문제 3
	자기 자신을 호출하는 함수를 이용해서 1부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보세요.
*/
#include <stdio.h>

int recursive_function(int n);
int loop_factorial(int n);

int main()
{
	int number;

	printf("n! 의 값을 구합니다. 원하는 값을 입력해주세요.");
	scanf("%d", &number);

	printf("%d\n", recursive_function(number));
	printf("%d\n", loop_factorial(number));

	return 0;

}

int recursive_function(int n)	//재귀함수로 구현한 팩토리얼.
{
	if(n > 1)
	{
		return n * recursive_function(n - 1);
	}
	else
		return 1;
}

int loop_factorial(int n)	//Loop 로 구현한 팩토리얼
{
	int result;

	for(result = 1; n > 1; n--)
	{
		result *= n;
	}

	return result;
}
