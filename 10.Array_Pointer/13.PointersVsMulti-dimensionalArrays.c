#include <stdio.h>

int main()
{
	// /* Two of 1D arrays */

	// int arr0[3] = { 1, 2, 3 };
	// int arr1[3] = { 4, 5, 6 };

	// int* parr[2] = { arr0, arr1 };	// an array of // 포인터가 담길 수 있는 메모리 공간 2개를 확보한 배열.

	// printf("%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%d\n", parr, &parr, parr[0], &parr[0], &arr0, *parr, arr0, &arr0[0], *arr0);


	// printf("%d\n", parr[1][2]);

	// int* temp = parr[1];

	// printf("%p %p\n", temp, &arr1[0]);

	// printf("\n");


	// for (int j = 0; j < 2; ++j)
	// {
	// 	for (int i = 0; i < 3; ++i)
	// 		printf("%d(==%d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i));	// 중요!!!
	// 	printf("\n");
	// }


	// /* 2D arrays are arrays of 1D arrays */

	// int arr[2][3] = { {1, 2, 3,}, {4, 5, 6} };

	// int *parr0 = arr[0];
	// int *parr1 = arr[1];

	// for (int i = 0; i < 3; ++i)
	// 	printf("%d ", parr0[i]);
	// printf("\n");

	// for (int i = 0; i < 3; ++i)
	// 	printf("%d ", parr1[i]);
	// printf("\n");



	// /* arrays of pointers works like a 2D array  */

	// int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

	// int* parr2[2] = { arr[0], arr[1] };


	// printf("%p %p", arr[0], &arr[0]);

	// for (int j = 0; j < 2; ++j)
	// {
	// 	for (int i = 0; i < 3; ++i)
	// 	{
	// 		printf("%d %d %d %d\n", arr[j][i], parr2[j][i], *(parr2[j] + i), *(*(parr2 + j) + i));
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");


	// /*
	// 	Notes
	// 	- parr[0] and parr[1] do not point valid memory by default
	// 	- &parr[0] != &arr[0]
	// 	- &parr[0] != parr[0] but & arr[0] == arr[0]
	// */

	// printf("%p\n", &parr[0]);	// different! parr[0] 이라는 포인트변수 자체의 주소.
	// printf("%p\n", parr[0]);	// arr[0] 의 주소!
	// printf("%p\n", arr);		// 위와 동일. (주소를 저장하는 별도의 메모리 공간을 가지고 있지는 않음. c언어의 문법중 하나.)
	// printf("%p\n", &arr[0]);	// 동일. address of array name is equal to the address of the first element.
	// printf("%p\n", arr[0]);		// 동일.
	// printf("%p\n", &arr[0][0]);	// 동일.



	// /* Array of string of diverse lengths example */

	// char* name[] = {"Aladdin", "Jasmine", "Magic Carpet", "Genie"};	//A의 주소, J의 주소, M의 주소, G의 주소.

	// const int n = sizeof(name) / sizeof(char*);

	// for (int i = 0; i < n; ++i)
	// 	printf("%s at %llu\n", name[i], (unsigned long long)name[i]);	// Use ull in x64 build. 주소값 : 글자수 + null character의 차이
	// printf("\n");


	// char aname[][15] = { "Aladdin over 15", "Jasmine", "Magic Carpet", "Genie", "Jafar" };

	// const int an = sizeof(aname) / sizeof(char[15]);

	// for (int i = 0; i < an; ++i)
	// 	printf("%s at %llu\n", aname[i], (unsigned long long)& aname[i]);	//	주소값 : 15 의 차이
	// printf("\n");

	// printf("%s", aname[0]);	// ???

	// printf("\n");


	// char* bname[] = {"hello", "hi", "ho", "Waiting for something great!"};	// 포인터의 배열.

	// printf("%zd\n", sizeof(bname));	// 포인터의 배열의 사이즈이므로 포인터의 사이즈(32byte) x 배열 갯수.

	// printf("\n");

	// char* cname[] = {"hello", "hi"};

	// printf("%zd\n", sizeof(cname));

	return 0;
}
