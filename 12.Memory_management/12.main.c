#include <stdio.h>
#include <time.h>
#include "12.my_rand.h"

int main() {
    my_srand((unsigned int)time(0));

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", my_rand() % 6 + 1);
    }

    return 0;
}