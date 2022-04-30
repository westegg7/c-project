#include <stdio.h>
#include <ctype.h>  // islower()
#include <stdbool.h>
#include <iso646.h>  // and, or, not

#define PERIOD '.'

int main()
{
	// bool test1 = 3 > 2 || 5 > 6; // true
	// bool test2 = 3 > 2 && 5 > 6; // false
	// bool test3 = !(5 > 6); // true, equivalent to 5 <= 6

	// printf("%d %d %d", test1, test2, test3);



	// char ch;
	// int count = 0;

	// while((ch = getchar()) != PERIOD)
	// {
	// 	if(ch != '\n' && ch != ' ')
	// 		count++;
	// }

	// printf("%d", count);




	// /* Short Circuit Evaluation
	// 	- Logical expressions are evaluated from left to right
	// 	- && and || are sequence points
	// */
	// int temp = (1 + 2) * (3 + 4);

	// printf("Before : %d\n", temp);

	// if(temp == 0 && (++temp == 1024)) // 중요!!! 왼쪽항이 거짓이면 오른쪽항의 참,거짓 여부는 카마와나이!! 예를 들어 첫번째 항이 참이어야 실행되는 함수를 뒤에 넣을 수 있다.
	// {
	// 	// do nothing
	// }
	// printf("After : %d\n", temp);




	// int a = 1, b = 2;
	// if(a++ > 0 && a + b == 4) // - && and || are sequence points  중요!!!
	// 	printf("%d %d\n", a, b); // 홍정모쌤은 논리연산자식에 증감연산자를 쓰는 것을 매우 싫어하신다!! 헷갈리기 때문



	return 0;
}
