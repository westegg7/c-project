#include <stdio.h>

// void swap(int a, int b)	//이 int a,b 변수는 main에 있는 a,b와는 다르게 새로이 선언된 변수이다.(다른 오브젝트, 값만 동일하게 들어올뿐) 따라서 주소도 다르다. 때문에 단순하게 변수만을 이용한 함수로는 스왑이 되지 않는다. 이함수에 변수 a와 b의 주소를 넣어줘야 한다.
// {
// 	printf("%p %p\n", &a, &b);

// 	int temp = a;	//a의 값을 temp가 가지고 있다. 따라서 변수a의 값을 바꿀 수 있다.
// 	a = b;
// 	b = temp;
// }

void swap(int* u, int* v)	//
{
	printf("%p %p\n", u, v);

	int temp = *u;
	*u = *v;
	*v = temp;	//temp는 변수
}

int main()
{
	int a = 123;
	int b = 456;

	printf("%p %p\n", &a, &b);

	// swap  -> 이런 패턴은 굉장히 많이 쓰인다. 함수형태로 만들어 보자.
	swap(&a, &b);	//123,456의 값만 들어온다. 변수의 이름은 같지만 주소가 다른 완전히 다른 변수. 지역변수

	printf("%d %d\n",a, b);

	return 0;
}
