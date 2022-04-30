#include <stdio.h>

void int_binary(const int num);

int main() {
    /*
        Bitwise shift operators

        - Left shift
        number << n : multiply number by 2^n

        - Right shift
        number >> n : divide by 2^n(for non-negative numbers)
    */

    // 8 bit integer cases %hhd로 8비트로 제한.
    
    printf("%d\n", 1 << 3);
    printf("%d\n", 8 >> 1);

    printf("%d\n", -119 >> 3);  // -15. 음수, 첫자리가 부호이다. 라이트시프트하면 왼쪽을 1로 채움.
    printf("%d\n", -119 / 8);   // -14. 
    printf("%d\n",  137 >> 3);  //-119와 이진수 패턴이 동일.
    printf("%d\n",  137 / 8);

    printf("%d\n", -119 << 4);
    printf("%d\n",  137 << 4);


    int a = 1;
    a <<= 3;
    a >>= 2;

    printf("Unsigned int %u\n", 0xffffffff);
    printf("Signed int %d\n", 0xffffffff);
    int_binary(0xffffffff);
    printf("Right shift by 3\n");
    int_binary(  (signed)0xffffffff >> 3);  //부호가 있는 정수 - 왼쪽이 1로 채워짐
    int_binary((unsigned)0xffffffff >> 3);  //부호가 없는 정수 - 왼쪽이 0으로 채워짐

    printf("\nUnsigned int %u\n", 0x00ffffff);
    printf("Signed int %d\n", 0x00ffffff);
    int_binary(0x00ffffff);
    printf("Right shift by 3\n");
    int_binary((signed)0x00ffffff >> 3);    //맨 앞이 0일 경우는 signed 와 unsigned 동일.
    int_binary((unsigned)0x00ffffff >> 3);

    return 0;
}

void int_binary(const int num) {
    printf("Decimal %12d == Binary ", num);

    size_t bits = sizeof(num) * 8;

    for (size_t i = 0; i < bits; i++) {
        const int mask = 1 << (bits - i - 1);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    printf("\n");
}