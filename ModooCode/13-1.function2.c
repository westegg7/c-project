/* 문제 5
특정한 수 N 을 입력받아서 N 을 소인수분해한 결과가 출력되는 함수.*/
#include <stdio.h>

void factorize(int quotient);

int main()
{
	int n;

	printf("소인수분해할 숫자를 입력해주세요. : ");
	scanf("%d", &n);

	printf("\n");

	factorize(n);

	return 0;
}



void factorize(int quotient)
{
	for (int divisor = 2; divisor <= quotient; divisor++)	// 몫과 제수를 변수로 설정.
	{
		if (quotient % divisor == 0)
		{
			quotient /= divisor;
			printf("%d", divisor);	//X를 여기에 쓰면 안됨.

			if (quotient == 1)
			{
				break;
			}
			printf(" X ");
			divisor--;	// 필수!!!
		}
	}
}
