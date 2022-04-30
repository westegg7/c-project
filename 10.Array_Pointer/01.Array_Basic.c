#include <stdio.h>

#define MONTHS 12		// symbolic constant, macro

int main()
{
	// /* Basic usage */
	// int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	// for(int i = 0; i < MONTHS; ++i)
	// 	printf("%d ", high[i]);
	// printf("\n");

	// float avg = 0.0;
	// for (int i = 0; i < MONTHS; i++)
	// 	avg += high[i];
	// printf("Average = %f\n", avg / (float)MONTHS);

	// high[0] = 1;	// 이미 위에서 배열이 초기화되었기때문에 하나씩 해야한다. 보통 for문을 이용해 초기화함.
	// high[1] = 2;
	// // high[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11, 12};	// NOT Working

	// /* Addresses */
	// printf("%p %p\n", high, &high[0]);	// 동일하다. 배열의 이름은 전체 할당받은 공간의 첫번째 주소.
	// for (int i = 0; i < MONTHS; ++i)
	// 	printf("%lld\n", (long long)&high[i]);	//10진수 정수로 표현하기 위해 long long으로 캐스팅. 64비트 체제에서는 int보다 8바이트인 long long으로 캐스팅한다. --> 4씩 증가.
	// printf("\n");



	// /* Compiler doesn't check whether indices are valid. c언어는 프로그래머를 믿는다. */
	// high[12] = 4; //배열을 벗어남. Runtime Error 이 에러는 vscode가 잡아주는 것.
	// high[-1] = 123; //Runtime Error



	// /* When array is not initialized */
	// static int not_init[4];	//TODO: try static(초기화를 0으로 시켜줌) (storage class)
	// for (int i = 0; i < 4; ++i)
	// 	printf("%d\n", not_init[i]);



	// /* Partially initialized */
	// int insuff[4] = { 2, 4 };
	// for (int i = 0; i < 4; ++i)
	// 	printf("%d\n", insuff[i]);	// 나머지 부분은 0으로 초기화된다.



	// /* Overlly initialized */
	// int over[2] = { 2, 4, 8, 16 };	// Compile Error



	// /* Omitting size */
	// const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 }; //배열의 크기를 직접 입력하지 않았을 경우 sizeof를 이용해서 원소의 갯수를 추측해서 for문을 돌린다. 주의!!동적할당에서는 적용되지 않는다.
	// printf("%lu\n", sizeof(power_of_twos));
	// printf("%lu\n", sizeof(int));
	// printf("%lu\n", sizeof(power_of_twos[0]));

	// for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)
	// 	printf("%d ", power_of_twos[i]);



	// /* Designated initializers */ // 어느 칸에 어떤값이 들어가야할지만 지정해준다.f
	// int days[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };
	// for (int i = 0; i < MONTHS; ++i)
	// 	printf("%d ", days[i]);



	// /* Specifying Array sizes */
	// int arr1[MONTHS];	//Symbolic integer constant
	// double arr2[123];	//Literal integer constant
	// float arr3[3*4 + 1];	// complie time에 미리 계산이 되어 결정된다.
	// float arr4[sizeof(int) + 1];	//위와 동일
	// // float arr5[-10];	//No
	// // float arr6[0];		//No
	// // float arr7[1.5];	//No
	// float arr8[(int)1.5];	//Yes

	// int n = 8;
	// float arr9[n];		//Variable-Length Array is optional from C11. 동적할당으로 구현가능. 컴파일러에 따라 안될 수도 있음.


	return 0;
}
