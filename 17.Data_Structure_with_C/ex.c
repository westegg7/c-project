#include <stdio.h>

int main()
{
    int a = 1;

    printf("%p\n", &a);

    a = a + 1;

    printf("%p\n", &a);

    return 0;
}