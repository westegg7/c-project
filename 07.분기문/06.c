#include <stdio.h>
#include <stdbool.h>

int main()
{
	unsigned num, divide;
	bool isPrime;

	scanf("%u", & num);

	isPrime = true; // 초기값을 true나 false로 설정하면 뒤의 반복문이 간단해진다!!!!

	for(divide = 2; (divide * divide) <= num; ++divide) // 제곱 부분은 생각하기가 어렵다. 큰 수의 소수판별을 위해 연산량을 줄이기 위해 사용한다.
	{
		if(num % divide == 0) // 초기값을 선언하지 않아, 처음 작성했던 코드는 isPrime이 true인 경우도 명시했었다.
		{
			isPrime = false;
			if(num == divide * divide)
				printf("%u is divisible by %u.\n", num, divide);
			else
				printf("%u is divisible by %u and %u.\n", num, divide, num/divide);
		}
	}


	if (isPrime) // isPrime 의 값이 참
		printf("%u is a prime number.\n", num);
	else //isPrime 의 값이 거짓
		printf("%u is not a prime number.\n", num);


	return 0;
}

