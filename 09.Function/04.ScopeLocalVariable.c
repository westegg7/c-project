#include <stdio.h>

// int a; // 문서 전체에서 접근 가능한 변수. 하지만 지역변수로 동일한 이름의 변수가 선언되면 먹힌다.

int int_max(int i, int j);

int int_max(int i, int j)
{
	int m;	// 변수가 사용될 수 있는 영역은 그 변수가 선언이 된 영역이다.
	m = (i > j) ? i : j;
	return m;
}

int main()
{
	// m = 123;

	int a;

	a = int_max(1, 2);

	printf("%d\n", a);
	printf("%p\n", &a);

	{
		int a;	// 안겨진 영역에서 동일한 이름의 변수를 선언하면 이전 과는 다른 변수가 된다. 메모리 주소가 다름.

		a = int_max(4, 5);

		printf("%d\n", a);
		printf("%p\n", &a);

		int b = 123;
	}
	// b = 456;	// 사용할 수 없음.ㄹ

	printf("%d\n", a);	// 영역밖으로 나와서 변수 a 가 다시 돌아옴.
	printf("%p\n", &a);

	return 0;
}
