/* 문제 2
유클리드 호제법을 이용해서 N 개의 수들의 최대공약수를 구하는 함수를 만들어 보시오.
	a = bq + r (0 <= r < b),
	gcd(a,b) = gcd(b,r)
*/
#include <stdio.h>

int gcd(int a, int b);

int main()
{
	int arr[100];
	int count_of_element = 0;

	for(int i = 0; ; i++)	// array에 n개의 수를 입력받음.
	{
		scanf("%d", &arr[i]);
		if(getchar() == 'q')
		{
			break;
		}
		count_of_element++;
	}

	int current_gcd = arr[0];

	for(int i = 1; i < count_of_element; i++)
	{
		current_gcd = gcd(current_gcd, arr[i]);
	}

	printf("GCD of the array is %d.", current_gcd);

	return 0;
}


int gcd(int a, int b)
{
	if(a % b == 0)
		return b;
	else
	{
		if((a % b) > b)
		{
			return gcd((a % b), b);
		}
		else
		{
			return gcd(b, (a % b));
		}
	}
}
