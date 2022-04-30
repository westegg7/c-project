#include <stdio.h>

int main()
{
	int a, b;

	a = 123;

	int *a_ptr;	// * : asterisk. 포인터 변수의 선언.

	a_ptr = &a;	//& : address of operator. 단항연산자.

	printf("%d %d %p\n", a, *a_ptr, a_ptr);	// address 출력은 %p를 사용한다.


	*a_ptr = 456;	// * : re-direction or de-referencing

	printf("%d %d %p\n", a, *a_ptr, a_ptr);	// a 또한 456으로 바뀜. 변수의 값을 가져오든 주소를 통해 가져오든 내부적으로 동일. 프로그래머 입장에서만 차이가 존재할 뿐. 이경우 주소는 변경 안됨.

	// b = a_ptr;	//정수형 변수에 주소를 대입 = warning. error가 아님. b = (int)a_ptr 의 가능성도 있기 때문.
	b = *a_ptr;

	printf("%d\n", b);


	*a_ptr = 789;

	printf("%d\n", b);	//456이 나온다. 위에서 b에 대입한 것은 순수한 값. redirection은 일어나지 않는다.
	printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b);	//a의 주소와 b의 주소는 다르다 -> a와 b는 다른 객체(object)다.

	a = 1004;
	printf("%d %d %p %d\n", a, *a_ptr, a_ptr, b);	//변수에 다른 값을 대입한다고 해서 주소가 바뀌지는 않는다.

	return 0;
}
