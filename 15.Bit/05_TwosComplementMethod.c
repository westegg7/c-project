#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const char num);  // 앞선 예제의 const unsigned char 를 char로 바꾼다. 음수를 다루어야하기 떄문

int main() {
    print_binary(127);
    print_binary(-127);
    print_binary(~127 + 1);

    print_binary(12);
    print_binary(-12);
    print_binary(~12 + 1);

    print_binary(7);
    print_binary(-7);
    print_binary(~-7 + 1);

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

void print_binary(const char num) {
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