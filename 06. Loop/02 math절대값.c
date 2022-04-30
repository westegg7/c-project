#include <stdio.h>
#include <math.h> //fabs() 괄호안의 값의 절대값을 출력.

int main()
{
	const double PI = 3.141592653589;
	double guess = 0.0;

	printf("input PI : ");
	scanf("%lf", &guess);

	//while(guess != PI)
	while(fabs(guess - PI) > 0.001)
	{
		printf("Fool! Try again!");
		scanf("%lf", &guess);
	}
	printf("Congraturations!");


	return 0;
}
