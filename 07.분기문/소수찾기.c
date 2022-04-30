#include <stdio.h>

int main()
{
	unsigned num, i;
	unsigned max = 100; // 소수를 찾을 정수 범위의 최대값

	for(num = 1; num <= max; ++num)
	{
		for(i = 2; i < num; ++i)
		{
			if(num % i == 0)
				break;
		}
		if(num == i)
			printf("%u  ", num);
	}

	return 0;
}
