#include <stdio.h>

int int_min(int, int);

int main()
{
	int i1, i2;

	while(1)
	{
		printf("Input two integers : ");

		if (scanf("%d %d", &i1, &i2) != 2) break;

		int lesser = int_min(i1, i2);	// 값을 반환한다.

		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

	}
	printf("End.\n");

	return 0;
}


int int_min(int i, int j) // 앞에 int 는 생략가능.
{
	// int min;	// Local Variable

	// if (i < j)
	// min = i;
	// else
	// 	min = j;

	// return min;


	return (i < j) ? i : j;	//이 방밥이 간결하고 알기쉽다.


	// return (flaot)min; //이 값은 정수 min을 float로 바꾸어도 반환값은 int로 되어있기 때문에 warning이 뜬다.


	// if (i < j)
	// 	return i;
	// else
	// 	return j;

	// printf("Error");	// 위의 분기문이 실수로 실행되지 않았을 경우에만 출력된다. 실수 방지.
	// exit(1);


	// return;	// return with no value
}
