#include <stdio.h>

void print_array(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void add_value(int arr[], int n, int val)	//여기서 배열에는 const 붙이면 안됨.
{
	int i;
	for (i = 0; i < n; i++)
		arr[i] += val;
}

int sum(const int arr[], const int n)
{
	int i;
	int total = 0;

	for (i = 0; i < n; i++)
		total += arr[i]; //++;		//wrong implementation. 의도한 실수. 위 parameter에 const를 붙이면 에러를 잡을 수 있다. 사람은 실수를 한다. 그러므로 const를 이용하는 습관을 통해 컴파일러단에서 오류를 잡을 수 있도록 하는 것이 좋다.

	return total;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);	// n = 5

	print_array(arr, n);
	add_value(arr, n, 100);
	print_array(arr, n);

	int s = sum(arr, n);

	printf("sum is %d\n", s);
	print_array(arr, n);

	return 0;
}
