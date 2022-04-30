/* 문제4
	계산기를 만들어 보세요. 사용자가 1을 누르면 +, 2를 누르면 -와 같은 방식으로 만들면 됩니다. 물론 이전의 계산 결과는 계속 누적되어야 하고, 지우기 기능도 있어야 합니다. (물론 하나의 함수에 구현하는 것이 아니라 여러개의 함수로 분할해서 만들어야겠죠?) (난이도 중)
*/
#include <stdio.h>

int plus(int a, int b);
int minus(int a, int b, int *arr);
int multiply(int a, int b, int *arr);
int division(int a, int b, int *arr);
int delete();	// 최근 입력된 배열값 하나를 지운다. 인덱스카운터도 -1.
int delete_all();	// 계산기의 c버튼. 배열의 모든 값을 초기화한다.

int main()
{
	int a, b;	// 연산을 하는 두 항.
	int result[10];	//연산의 결과가 저장되는 배열 선언.
	int i_count = 0;	// 배열의 인덱스 카운트
	char k;	// 연산자.


	printf("Calculate!");

	while(1)
	{
		if(getchar() == 'q')
		{
			break;
		}
		scanf("%d %c %d ", &a, &k, &b);

		if(k == '+')
		{
			i_count++;
			result[i_count] = plus(a, b);
		}

		printf("%d", result[i_count]);
		// if(k == '-')
		// {
		// 	minus(a, b, *result)
	}
	return 0;
}


int plus(int a, int b)
{
	return a + b;
}


// int minus(int a, int b, int *arr)
// int multiply(int a, int b, int *arr)
// int division(int a, int b, int *arr)
// int delete()
