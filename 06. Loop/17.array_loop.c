#include <stdio.h>

#define SIZE 5

int main()
{
	int my_arr[SIZE];
	int sum = 0;
	int i;

	printf("Enter %d numbers : ", SIZE);

	for(i = 0; i < SIZE; ++i)
	{
		scanf("%d", &my_arr[i]);
	}
	for(i = 0; i < SIZE; ++i)
	{
		sum += my_arr[i];
	}

	printf("Sum : %d", sum);


	return 0;
}

