#include <stdio.h>

double average(double arr1[], int n);	//함수에서 배열을 매개변수로 받을때는 배열이 아닌 포인터로 받는다. 내부적으로 arr1은 포인터처럼 처리가 됨(첫번째 주소) = 크기는 8바이트. 그래서 n변수로 크기를 따로 지정해준다. 이후 동적할당 참조.

//double average(double * arr1, int n);
//double average(double [], int n);	//body 부분은 arr1[]
//double average(double *, int n);	//body 부분은 * arr1. 이렇게 많이 쓴다.


int main()
{
	double arr1[5] = { 10, 13, 12, 7, 8 };
	// double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	double arr2[3] = { 1.8, -0.2, 6.3 };	// size is different

	printf("Address = %p\n", arr1);
	printf("Size = %zd\n", sizeof(arr1));

	printf("Avg = %f\n", average(arr2, 3));	// Argument 필요



	return 0;
}


double average(double arr1[], int n)	//함수에서 배열을 매개변수로 받을때는 배열이 아닌 포인터로 받는다. 내부적으로 arr1은 포인터처럼 처리가 됨(첫번째 주소) = 크기는 8바이트. 그래서 n변수로 크기를 따로 지정해준다. 이후 동적할당 참조.
{
	double avg = 0.0;
	for (int i = 0; i < n; ++i)
	{
		avg += arr1[i];
	}
	avg /= (double)n;

	return avg;
}
