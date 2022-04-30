#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

void char_to_binary(unsigned char uc) {
    const int bits = CHAR_BIT * sizeof(unsigned char);
    for (int i = bits - 1; i >= 0; i--)
        printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes) {
    for (int i = 0; i < bytes; i++) 
        char_to_binary(data[bytes - 1 - i]);
    printf("\n");
}

int main() {
    struct {
        bool option1 : 1;
        //bool       : 0;
        bool option2 : 1;
        unsigned long long option3 : 1;
    } bbf;

    printf("%zu bytes\n", sizeof(bbf));

    struct {
        unsigned short option1 : 8;
        unsigned short option2 : 7;
        //unsigned short : 0;
        unsigned short option3 : 1;
    } usbf;

    printf("%zu bytes\n", sizeof(usbf));

    struct {
        unsigned int option1 : 1;
        unsigned int option2 : 1;
    } uibf;

    printf("%zu bytes\n", sizeof(uibf));


    return 0;
}