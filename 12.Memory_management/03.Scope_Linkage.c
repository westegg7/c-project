#include <stdio.h>

/*
    Variable scopes (visibility)
    - block, function, function prototype, file.
*/

int el;
static int il;

void testLinkage();

int main() {
    el = 1024;

    testLinkage();

    printf("%d\n", el);

    return 0;
}
