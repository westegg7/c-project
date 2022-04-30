#include <stdio.h>

int main()
{
	// int * ptr = 0;	//try double*, long long*, char*, void* 원래는 주소를 넣어야한다.
	// // void 포인터는 자료형이 없기때문에 사이즈를 알 수 없으므로 산술연산이 불가.

	// // printf("%d", *ptr);//Error in this lecture ->프로그램이 걍 종료됨. 디레퍼런싱을 하면 문제가 생김. ptr = 0 은 의미가 없다.

	// printf("%p %lld\n", ptr, (long long) ptr);

	// ptr ++; // try -=, ++, --, -, +

	// printf("%p %lld\n", ptr, (long long) ptr); //int자료형이므로 4가 증가함.



	//ptr = -ptr;	// Not working
	//ptr = +ptr;	// Not working



	/* Subtraction */
	int arr[10];
	int* ptr1 = &arr[3], * ptr2 = &arr[5];

	// ptr2 = ptr1 + ptr2;	//Not working
	int i = ptr2 - ptr1;	//두 주소값간의 차이 거리.

	printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);


	return 0;
}
