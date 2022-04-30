#include <stdio.h>
#include <stdlib.h>

int main() {
    /* 
        Well alligned structure
    */
    struct Aligned {
        int a;
        float b;
        double c;
    };

    struct Aligned a1, a2;  // memory allocation

    /*
        padding (struct member alignment)
        - 1 word : 4 bytes in x86, 8 bytes in x64 (효율적인 데이터전달을 위해 cpu와 메모리가 데이터를 전달하는 단위.)
    */

    struct Padded1 {
        char a;
        float b;
        double c;
    };

    /*
        without padding
         0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20
        |a|float b|double c          | ? ? ?
        1  +  4    +   8  = 13
    */

    /*
        with padding
         0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20
        |char a |float b|double c             | ? ? ?
            4   +   4   +     8  = 16
    */

    struct Padded1 p1;

    printf("\nstruct Padded1 p1\n");
    printf("Sizeof %zd\n", sizeof(p1)); // 4 + 4 + 8
    printf("%lld\n", (long long)& p1);
    printf("%lld\n", (long long)& p1.a);
    printf("%lld\n", (long long)& p1.b);
    printf("%lld\n", (long long)& p1.c);

    // char a는 1바이트를 차지해야하는데 '컴파일러'에서 3바이트를 추가해서 총 4바이트의 공간을 가진다.
    // cpu 와 메모리가 데이터를 주고받을때 데이터를 1 word 단위로 묶어서 보낸다.
    // - 1 word : 4 bytes in x86, 8 bytes in x64
    // 위의 경우에서 padding이 없이 보낸다면 double c 의 데이터는 한번에 보내지지 않기 때문에 효율적이지 않다.


    struct Padded2 {
        float a;
        double b;
        char c;
    };

    /*
         0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
        | float a       | double b            | char c                |
        8   +   8   +    8    =   24

        데이터는 동일하지만 padding 때문에 구조체 멤버의 순서에 따라 메모리 크기가 달라질 수 있다..
    */

    struct Padded2 p2;

    printf("\nstruct Padded1 p1\n");
    printf("Sizeof %zd\n", sizeof(p2)); // 8 + 8 + 8
    printf("%lld\n", (long long)& p2);
    printf("%lld\n", (long long)& p2.a);
    printf("%lld\n", (long long)& p2.b);
    printf("%lld\n", (long long)& p2.c);



    return 0;
}