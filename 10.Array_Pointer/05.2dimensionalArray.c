#include <stdio.h>

int main()
{
	int arr[2][3] = { { 1, 2, 3, },
						{ 4, 5, 6 } };

	// int arr[2][3] = { 1, 2, 3, 4, 5, 6 };
	// int arr[2][3] = { 1, 2 };// in sufficient initiallizer

	// printf("%d\n\n", arr[0][1]);

	// for (int j = 0; j < 2; ++j)	//Note: inner loop uses i. why?
	// {
	// 	for (int i = 0; i < 3; ++i)
	// 		printf("%d ", arr[j][i]);	//2차원 배열을 for문으로 묶을 때는 arr[j][i] 식으로 i가 안쪽루프. 더 빠르다.

	// 	printf("\n");
	// }
	// printf("\n");


	int *ptr = &arr[0][0];
	for (int k = 0; k < 6; ++k)
		printf("%d ", ptr[k]);
	printf("\n\n");


	printf("%zd %zd\n", sizeof(arr), sizeof(arr[0]));	// 24	12(3개짜리가 2개. 3개짜리의 크기가 나온 것.)
	printf("\n");

	return 0;
}
