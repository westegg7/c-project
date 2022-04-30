#include <stdio.h>
#include <math.h>   // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()

unsigned char to_decimal(const char bi[]);

int main() {
    printf("Binary (string) to Decimal conversion\n");

    printf("%d\n", to_decimal("00000110")); // 1*(2^2) + 1*(2^1) = 4 + 2 = 6
    printf("%d\n", to_decimal("00010110")); // 1*(2^4) + 1*(2^2) + 1*(2^1) = 16 + 4 + 2 = 22

    printf("%d\n", to_decimal("10010101"));

    return 0;
}

unsigned char to_decimal(const char bi[]) {
    unsigned char d = 0;

    // int n = sizeof(bi) / sizeof(char);
    const size_t bits = strlen(bi);

    for (size_t i = 0; i < bits; i++) {
        if (bi[i] == '1') {
            d += (int)pow(2, bits - i - 1);
        } else if (bi[i] != '0') {
            printf("Wrong character : %c\n", bi[i]);
            exit(1);
        }
    }

    return d;
}