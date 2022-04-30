/* 10의 원소를 입력받아 그 원소를 내림차순으로 출력하는 함수를 작성하시오. */
#include <stdio.h>

int print_sort(int *parr);

int main()
{
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	print_sort(arr);

	return 0;
}



int print_sort(int *parr)
{
	int a[10]; 	// 원배열의 순서는 바꾸고싶지 않기 때문에.
	int max;

	for (int i = 0; i < 10; i++)
	{
		a[i] = parr[i];
	}

	for(int j = 0; j < 9; j++)	// i와 i+1이 반복되므로 10대신 9가 들어간다.
	{
		for(int i = 0; i < 9; i++)
		{
			if(a[i] < a[i + 1])
			{
				max = a[i];
				a[i] = a[i+1];
				a[i+1] = max;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
