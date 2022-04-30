#include <stdio.h>

int main()
{
	double seed,  target, interest;
	int year;

	printf("Input your seed money : ");
	scanf("%lf", &seed);

	printf("Input target money : ");
	scanf("%lf", &target);

	printf("Annual interest : ");
	scanf("%lf", &interest);

	double fund = seed;
	int i = 0;

	while(fund < target)
	{
		fund += fund * interest / 100.0;
		i++;
		printf("%f\n", fund);
	}

	year = i;

	printf("It takes %d years", year);

	return 0;
}
