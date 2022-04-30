#include <stdio.h>

double average(double*, double*);

int main()
{
	double arr1[5] = { 10, 13, 12, 7, 8 };

	printf("Avg = %f\n", average(arr1, arr1 + 5));	//배열의 마지막 항의 뒤까지

	return 0;
}

double average(double* start, double* end)
{
	int count = end - start;
	double avg = 0;

	while (start < end)
	{
		avg += *start++;	//*start는 값. -> avg에 값을 더해준다. ++은 포인터연산
	}
	avg /= (double)count;

	return avg;
}
