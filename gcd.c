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
	int n;

	printf("몇개의 수의 gcd를 구하는가\n");
	scanf("%d", &n);

	printf("gcd를 구하고싶은 %d개의 수를 입력하시오. \n", n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int current_gcd = arr[0];

	for(int i = 1; i < n; i++)
	{
		current_gcd = gcd(current_gcd, arr[i]);
	}

	printf("gcd는 %d\n", current_gcd);

	return 0;
}

int gcd(int a, int b)
{
	if(a % b == 0)
		return b;
	else
	{
		if((a % b) > b)
			return gcd((a % b), b);
		else
			return gcd(b, (a % b));
	}
}
