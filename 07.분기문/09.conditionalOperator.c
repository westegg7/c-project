#include <stdio.h>
#include <stdbool.h>

int main()
{
	int temp;

	// temp = true ? 1024 : 7; // 삼항연산자
	// printf("%d\n", temp);

	// temp = false ? 1024 : 7; // 삼항연산자
	// printf("%d\n", temp);


	// int number;
	// scanf("%d", &number);
	// int print;

	// const bool is_even = (number % 2 == 0) ? true : false; // 따로 있던 것을 한줄로 합치고 선언과 동시에 const로 초기값을 고정시킨다. 조건에 따라 다른값으로 초기화하고싶으면 조건연산자를 많이 쓴다. ?는 연산자우선순위가 매우 낮아서 괄호는 필요없지만 괄호를 쓰는게 더 시인성이 좋다.

	// if(is_even) //is_even 의 값이 true
	// 	printf("Even");
	// else
	// 	printf("Odd");

	// (number % 2 == 0) ? printf("Even") : printf("Odd"); // 이렇게 단 한줄로도 구현가능. 하지만 flag를 선언하는 것이 일반적.


	int a = 1, b =2;
	int max = (a > b) ? a : b;

	return 0;
}
