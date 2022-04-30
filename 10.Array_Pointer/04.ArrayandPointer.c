#include <stdio.h>

int main()
{
	int arr[10];

	int num = sizeof(arr) / sizeof(arr[0]);	// 이 형태!
	for (int i = 0; i < num; ++i)
		arr[i] = (i + 1) * 100;

	int* ptr = arr;	// 배열의 이름이 배열을 대표하는 메모리주소. 내부적으로 포인터와 유사.

	printf("%p %p %p \n", ptr, arr, &arr[0]);

	ptr += 2;

	printf("%p %p %p\n", ptr, arr + 2, &arr[2]);	// ptr(포인터)로 &arr[]을 대체할 수 있다.

	//Note: arr += 2; // invalid 배열의 이름이 포인터처럼 사용될 수 있지만 연산은 할 수 없다.

	printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]);

	// Warning
	printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]);	// 괄호가 없는 경우.

	printf("\n");


	for (int i = 0, *ptr = arr; i < num; ++i)	// 다른 스코프에 있으므로 위에서 선언된 ptr 과는 다른 변수이다.
	{
		// printf("%d %d\n", *ptr++, arr[i]);
		// printf("%d %d\n", *(ptr + i), arr[i]);
		printf("%d %d\n", *ptr + i, arr[i]);	// 주의!! 명확하게 표현하자.
	}

	return 0;
}
