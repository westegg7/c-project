#include <stdio.h>

int main()
{
	//type qualifiers: const, volatile, ... 변수를 상수로 바꿔준다.

	const double PI = 3.14159;
	// PI = 1.234;

	const int arr[5] = { 1, 2, 3, 4, 5 };
	// arr[1] = 123;

	const double arr2[3] = { 1.0, 2.0, 3.0 };

	const double* const pd = arr2;	//첫번째 const의 의미: pd 포인터가 가리키는 변수 메모리값 변경 X. 포인터 변수가 가지고 있는 주소값은 변경 가능.(두번째 const가 없을 시)
	// 두번째 const: 포인터변수의 값자체, 즉 주소값을 못바꾼다.

	// *pd = 3.0;	// pd[0] = 3.0; arr2[0] = 3.0;
	// pd[2] = 1024.0;	//arr[2] = 1024.0;	// pointer변수를 배열처럼 사용할 수 있다.

	printf("%f %f\n", pd[2], arr2[2]);

	// pd++;	//allowed

	printf("%f %f\n", pd[2], arr2[2]);



	return 0;
}
