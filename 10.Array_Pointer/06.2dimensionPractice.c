#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main()
{
	double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

	/*
	1. Use 2D array
	2. Print data
	3. Calculate and print yearly average temperatures of 3 years
	4. Calculate and print monthly average temperatures for 3 years
	*/

	int i, j;

	double arr[YEARS][MONTHS] = {
		{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
		{ -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
		{ -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }
	};


	printf("[Temperature Data]\n");

	printf("Year index : ");
	for (int m = 0; m < MONTHS; ++m)
	{
		printf("\t%d ", m + 1);
	}
	printf("\n");

	for (j = 0; j < YEARS; j++)
	{
		printf("Year %d     :  ", j);
		for (i = 0; i < MONTHS; i++)
		{
			printf("\t%.1f", arr[j][i]);
		}
		printf("\n");
	}

	printf("\n");

	printf("[Yearly average temperatures of 3 years]\n");
	for (j = 0; j < YEARS; j++)
	{
		double sum = 0.0;
		for (i = 0; i < MONTHS; i++)
		{
			sum += arr[j][i];
		}
		printf("Year %d : average temperature = %.1f\n", j, sum / MONTHS);
	}

	printf("\n");

	printf("[Monthly average temperatures of 3 years]\n");
	printf("Year index : ");
	for (int m = 0; m < MONTHS; ++m)
	{
		printf("\t%d ", m + 1);
	}
	printf("\n");
	printf("Avg temps  : \t");
	for (i = 0; i < MONTHS; i++)
	{
		double sum = 0.0;
		for (j = 0; j < YEARS; j++)
		{
			sum += arr[j][i];
		}
		printf("%.1f\t", sum / YEARS);

	}

	return 0;
}
