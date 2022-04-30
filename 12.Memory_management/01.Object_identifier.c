#include <stdio.h>

int main() {
    /*
        Object
        - "An object is simply a block of memory that can store a value." (KNK p.487)
        - Object has more developed meaning in C++ and Object Oriented Programming (OOP)

        Identifiers
        - Names for variables, functions, macros, and other entities. (KNK p.25)
    */

    // int var_name = 3;

    // int* pt = &var_name;
    // *pt = 1;

    // int arr[100];
    // arr[0] = 7;

    const char* str = "Constant string";    
    // 포인터가 가리키는 곳의 내용을 바꿀 수 없다. 
    // 스트링 리터럴의 에러의 경우 런타임에러가 발생하므로 const 를 붙이는 습관을 들이자. 
    // char* const str : 포인터값, 즉 주소값을 바꿀 수 없다.
    str = "Second string";  // 이 경우 str의 값, 즉 가리키고자하는 주소값을 바꾼다.
    // str[0] = 'A';   // error. 리터럴은 읽기전용이다. 밑의 예와 비교해보자.
    // "Constant string" = "Second string"  // impossible
    puts(str);

    char str2[] = "String in an array";
    str2[0] = 'A';  // OK

    return 0;
}