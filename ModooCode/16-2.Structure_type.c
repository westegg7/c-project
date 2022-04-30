#include <stdio.h>
struct BigNum {
	int i_digit[100];	// 정수 부분
	int d_digit[100];	// 소수 부분
	int i_total_digit;	// 전체 사용되고 있는 정수부분 자리수
	int d_total_digit;	// 전체 사용되고 있는 소수부분 자리수
	char sign;	// 부호, 0 이면 양수, 1 이면 음수 0 은 양수로 간주한다.
}
