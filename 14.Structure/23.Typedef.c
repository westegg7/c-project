#include <stdio.h>

char char3[3] = { 'A', 'B', 'C' };

int* function(int);

char(*complicated_function1())[3]   // Function Returns Pointer to char[3]
{
    return &char3;
};
// char 3개짜리 배열의 포인터를 반환하는, 매개변수가 없는 함수.
// Not, char[3]* complicated_function(); 문법상 안됨. 

typedef char(*FRPTC3())[3]; // Function returns pointer to char[3]
typedef char(*(*PTFRPTC3)())[3];

char(*(*fptr1)())[3] = complicated_function1;   // 위 함수에 대한 포인터 변수를 선언.

FRPTC3 *fptr2 = complicated_function1;
PTFRPTC3 fptr3 = complicated_function1;

/* Use typedef to make declarations simpler */
// 2번째 용법

typedef char c3[3]; // char 3개짜리 배열을 c3라는 이름의 자료형으로 선언. typedef char[3] c3 가 아니다. 

c3* complicated_function2() {
    return &char3;
}

int main() {
    char(*ret_val)[3] = fptr1();
    //  char[3] 배열을 가리키는 포인터변수 ret_val 에 fptr1() 의 리턴값(주소값)을 대입.

    printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

    c3* my_c3 = fptr2();
    // char[3] 배열을 가리키는 포인터변수 my_c3에 fptr2() 의 리턴값(주소값)을 대입

    printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);

    // char* ptr[3] 이 아닌 char(*ptr)[3]이기 때문에 *를 통해 my_c3[0]이 아닌 (*my_c3)[0]의 형태.
    // char 포인터 3개의 배열이 아닌 char[3] 포인터 하나이기 때문에 배열처럼 사용할 수 없음. 

    return 0;
}