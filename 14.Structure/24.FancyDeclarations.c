#include <stdio.h>

int temp(int a) {
    return 0;
}

int (*g(int a))(int) {
    return temp;
}

int main() {
    int* ap[10];

    typedef int* pint;
    pint ap2[10];

    float* fp(float);

    typedef float* pfloat;
    pfloat fp2(float);

    void (*pf)(int);

    int* (*x[10])(void);    // array of pointers to functions with no arguments returning pointer to int.
    //함수 포인터의 배열


    
    /* A function can't return an array */

    //int f(int)[]; // Wrong

    /* BUT it can return a pointer to an array */

    int(*f(int))[] ; // 함수 포인터의 선언.!!  pointer to function with int argument returning array of int??
    //int를 매개변수로하는 f는 반환한다. int(*)[]를.


    /* A function can't return a function */

    //int g(int)(int);  // Wrong

    /* BUT it can return a pointer to a function */

    int (*g(int))(int);

    /* An array of functions aren't possible */

    //int a[10](int);   // Wrong

    /* BUT an array of function pointers are possible */

    int (*x2[10])(int);

    /* Using typedef to simplify declarations */

    typedef int FCN(int);
    typedef FCN* FCN_PTR;
    typedef FCN_PTR FCN_PTR_ARRAY[10];

    FCN_PTR_ARRAY x3;
    // 여기서 x3 와 x2는 형이 같다. int를 매개변수로 하고 int를 반환하는 함수에 대한 포인터가 10개 있는 배열








    



    return 0;
}