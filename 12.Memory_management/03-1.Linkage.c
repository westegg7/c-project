#include <stdio.h>

extern int el;
//extern int il;

void testLinkage() {
    printf("Do Something called\n");
    printf("%d\n", el);
    // printf("%d\n", il);

    el++;
}