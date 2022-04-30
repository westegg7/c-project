/* 변수의 주소값, 즉 포인터가 가리키는 변수를 스왑하는 함수를 만든다.
	메인함수와 스왑함수의 스코프가 달라 스왑함수내에서 포인터를 직접 스왑할 수 없기때문에 이중포인터를 통해 스왑한다.
*/

#include <stdio.h>

int pswap(int **ppa, int **ppb);

int main()
{
	int a, b;
	int *pa, *pb;

	pa = &a;
	pb = &b;

	printf("pa 가 가리키는 변수의 주소값 : %p\n", pa);
	printf("pa 의 주소값 : %p\n", &pa);
	printf("pb 가 가리키는 변수의 주소값 : %p\n", pb);
	printf("pb 의 주소값 : %p\n", &pb);

	printf(" ---------- 호출 ---------- \n");
	pswap(&pa, &pb);
	printf(" ---------- 호출끝 ---------- \n");

	printf("pa 가 가리키는 변수의 주소값 : %p\n", pa);
	printf("pa 의 주소값 : %p\n", &pa);
	printf("pb 가 가리키는 변수의 주소값 : %p\n", pb);
	printf("pb 의 주소값 : %p\n", &pb);

	return 0;
}

int pswap(int **ppa, int **ppb)
{
	int *temp = *ppa;	// ppa 는 더블포인터, *ppa 는 pa를 가리키고 pa 에는 a의 주소값이 들어있다. 그것을 temp 포인터 변수에 대입. int *temp = pa 와 동일하지만 함수의 정의이기 때문에 위와같이 적는다.

	printf("ppa 가 가리키는 변수의 주소값 : %p\n", ppa);
	printf("ppb 가 가리키는 변수의 주소값 : %p\n", ppb);

	*ppa = *ppb;
	*ppb = temp;

	return 0;
}
