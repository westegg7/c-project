#include <stdio.h>

#define NUM_DAYS 365

int main()
{
	char my_chars[] = "Hello, World!"; // \0 까지

	int daily_temperature[NUM_DAYS];
	double stock_price_history[NUM_DAYS];

	printf("%zd\n", sizeof(stock_price_history));
	printf("%zd\n", sizeof(double) * NUM_DAYS);
	printf("%zd\n", sizeof(stock_price_history[0]));

	return 0;
}
