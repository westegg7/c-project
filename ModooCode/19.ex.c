#include <stdio.h>

int main()
{
	int n;

	printf("Input array length : ");
	scanf("%d", &n);

	float my_arr[n];	//NOTE : cannot change length after declaration.

	for (int i = 0; i < n; i++)
		my_arr[i] = (float)i;

	for (int i = 0; i < n; i++)
		printf("%f\n", my_arr[i]);

	return 0;
}
