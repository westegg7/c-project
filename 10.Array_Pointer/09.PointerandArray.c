#include <stdio.h>

int main()
{
	int arr[5] = { 100, 200, 300, 400, 500 };
	int* ptr1, * ptr2, * ptr3;

	int i;
	ptr1 = arr;

	printf("%p %d %p\n", ptr1, *ptr1, &ptr1);	//배열의 첫주소, *(첫번째 원소의 주소), ptr1자체의 주소

	ptr2 = &arr[2];

	printf("%p %d %p\n", ptr2, *ptr2, &ptr2);

	ptr3 = ptr1 + 4;

	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

	printf("%td\n", ptr3 - ptr1);	//Note: t is for pointer difference





	return 0;
}
