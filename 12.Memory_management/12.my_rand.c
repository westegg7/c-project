#include <stdio.h>
#include "12.my_rand.h"

static unsigned int next = 1;

int my_rand() {
    next = next * 1103515245 + 1234;
    next = (unsigned int)(next / 65546) % 32768;

    return (int)next;
}

void my_srand(unsigned int seed) {
    next = seed;
}