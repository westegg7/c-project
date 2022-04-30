#include <stdio.h>

int main()
{
	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

	printf("%llu\n", (unsigned long long)arr2d);	// Use unsigned long long in x64
	printf("%llu\n", (unsigned long long)arr2d[0]);
	printf("%llu\n", (unsigned long long)* arr2d);
	printf("%llu\n", (unsigned long long)* arr2d[0]);
	printf("%llu\n", (unsigned long long)arr2d[0][0]);


	printf("\n");

	// arr2d points to arr2d[0] (not arr2d[0][0]), KNK Ch. 12.4

	printf("%llu\n", (unsigned long long)* arr2d);
	printf("%llu\n", (unsigned long long)& arr2d[0]);	// C language allows this
	printf("%llu\n", (unsigned long long)& arr2d[0][0]);
	printf("%f %f\n", arr2d[0][0], **arr2d);
	printf("\n");

	printf("%llu\n", (unsigned long long)(arr2d + 1));
	printf("%llu\n", (unsigned long long)(&arr2d[1]));
	printf("%llu\n", (unsigned long long)(arr2d[1]));
	printf("%llu\n", (unsigned long long)(*(arr2d + 1)));	//arr2d[1] 의 주소
	printf("%llu\n", (unsigned long long)(&arr2d[0] + 1));
	printf("%llu\n", (unsigned long long)(&arr2d[1][0]));
	printf("\n");

	printf("%f\n", *(*(arr2d + 1) + 2));
	printf("\n");

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 4; ++i)
		{
			printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));

			*(*(arr2d + j) + i) += 1.0f;	// arr2d[j][i] += 1.0f
		}
	}
	printf("\n");



	return 0;
}
