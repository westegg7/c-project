#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main() {
    unsigned char i = to_decimal("01000110");       // 70
    unsigned char mask = to_decimal("00000101");    // 5

    // print_binary(i);
    // print_binary(mask);
    // print_binary(i & mask);
    // print_binary(121);

    unsigned char a = 6;
    unsigned char b = 5;

    printf("%d\n", a);
    print_binary(a);

    printf("%d\n", b);
    print_binary(b);

    printf("%d\n", a & b);
    print_binary(a & b);

    printf("%d\n", a | b);
    print_binary(a | b);

    printf("%d\n", a ^ b);
    print_binary(a ^ b);

    printf("%d\n", ~a);
    print_binary(~a);



    return 0;
}

unsigned char to_decimal(const char bi[]) {
    unsigned char d = 0;
    size_t len = strlen(bi);

    for (int i = 0; i < len; i++) {
        if (bi[i] == '1') {
            d += (unsigned char)pow(2, len - i - 1);
        }
    }

    return d;
}

// void print_binary(const unsigned char num) {
//     printf("Decimal %3d \t== Binary ", num);
//     int temp = num;

//     // i가 감소하는 반복문의 경우 size_t 를 사용하지 못한다. 
//     // size_t는 unsigned char 이기때문에 0이하가 되지 않음.
//     for (int n = 7; n >= 0; n--) {
//         if (temp >= (int)pow(2, n)) {
//             printf("1");
//             temp -= (int)pow(2, n);
//         }
//         else
//             printf("0");
//     }
//     printf("\n");
// }

/* 강의 */
void print_binary(const unsigned char num) {
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;

    for (size_t i = 0; i < bits; i++) {
        const unsigned char mask = (unsigned char)pow(2, bits - i - 1);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    printf("\n");
}