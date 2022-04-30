#include <stdio.h>

int main()
{
	/* for(initialize; test; update)
		statement
	*/

	for(int i = 10; i > 0; i--)
		printf("%d ", i);

	printf("\n");

	for(int i = 0; i < 100; i += 8)
		printf("%d ", i);

	printf("\n");

	for(char c = 'A'; c <= 'Z'; c++)
		printf("%c ", c);

	printf("\n");

	for(int i = 0; i * i < 10; i++)
		printf("%d ", i);

	printf("\n");

	for(int x = 1, y = 5; y <= 20; y = (x++ * 3) + 10) // 후위연산!!
		printf("%d %d\n", x, y);

	printf("\n");

	for(double d = 100.0; d < 300; d = d * 1.1)
		printf("%.1f ", d);

	printf("\n");

	int i = 0;
	for(printf("Let's go!\n"); i != 7; scanf("%d", &i))
		; //null statement

	for(int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n)
		printf("%d %d\n", n, nsqr);

	int k, g;
	k = 1;
	k++, g = k; // comma is a sequence point
	printf("%d %d\n", k, g);

	int x, y, z;
	z = x = 1, y = 2;

	z = ((x = 1), (y = 2)); // 콤마 연산자의 오른쪽값이 전체의 값이 된다.
	printf("%d %d %d", x, y, z);

	return 0;
}
