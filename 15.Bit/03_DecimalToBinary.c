#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);
void int_binary(const int num);

int main() {
    unsigned char i = to_decimal("01000110");       // 70
    unsigned char mask = to_decimal("00000101");    // 5

    int_binary(i);
    int_binary(mask);
    int_binary(i & mask);
    int_binary(121);



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

void int_binary(const int num) {
    printf("Decimal %12d == Binary ", num);

    const size_t bits = 8;

    for (size_t i = 0; i < bits; i++) {
        const int mask = 1 << (bits - i - 1);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    printf("\n");
}