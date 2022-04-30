#include <stdio.h>
#include <ctype.h>

/*
    ToUpper()와 ToLower()는 구조가 같고 내부에서 쓰는 함수만이 다르다.
    따라서 해당 함수를 매개변수로 받는 하나의 함수로 하는 것이 유지보수에 효율적이다.
*/

void ToUpper(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void UpdateString(char* str, int(*pf)(int)) {
    while (*str) {
        *str = pf(*str);
        str++;
    }
}

int main() {
    char str[] = "Hello, World!";

    void (*pf)(char*);

    pf = ToUpper;   // Name of a function is a pointer
    // pf = &ToUpper;   // acceptable
    // pf - ToUpper(str);   // Not acceptible in C  함수의 실행을 의미.

    printf("String literal %lld\n", (long long)("Hello, World!"));  // 스택, 주소값 낮음.
    printf("Function pointer %lld\n", (long long)ToUpper);          // 스택.
    printf("Variable %lld\n", (long long)str);                      // 텍스트 세그먼트,  주소값 높음.

    (*pf)(str);
    //pf(str);  // K&R X, ANSI OK

    printf("ToUpper %s\n", str);

    pf = ToLower;

    pf(str);

    printf("ToLower %s\n", str);

    UpdateString(str, toupper); // 함수의 주소를 매개변수로 가져온다.

    printf("ToUpper %s\n", str);

    UpdateString(str, tolower);

    printf("ToLower %s\n", str);


    return 0;
}