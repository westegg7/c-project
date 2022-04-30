#include <stdio.h>

void plusone_2dimension(int (*parr)[3], int n);

int main()
{
	int arr[2][3] = { {1, 2, 3}, { 4, 5, 6} };

	for(int j = 0; j < 2; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			printf("%d ", arr[j][i]);
		}
	}

	plusone_2dimension(arr, 2);

	for(int j = 0; j < 2; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			printf("%d ", arr[j][i]);
		}
	}

	return 0;
}


void plusone_2dimension(int (*parr)[3], int n)
{
	for(int j = 0; j < n; j++)
	{
		for(int i = 0; i < 3; i++)
		{
			parr[j][i]++;
		}
	}
	printf("\n");
}
