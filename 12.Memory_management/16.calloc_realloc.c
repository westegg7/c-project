#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;

    int* ptr = NULL;

    // ptr = (int*)malloc(sizeof(int) * n);  // 초기화를 안해줌. (gcc에선 해줌)
    ptr = (int*)calloc(n, sizeof(int)); // contiguous allocation    // 0으로 초기화
    if (!ptr)
        exit(1);

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr[i]);
    printf("\n");


    /*
        realloc() KNK p. 422
        - doesn't initialize the bytes added. (but in gcc, initialize)
        - returns NULL if can't enlarge the memory block
        - if first argument is NULL, it behaves like malloc()
        - if second argument is 0, it frees the memory block.
    */

    for (int i = 0; i < n; ++i)
        ptr[i] = i + 1;

    n = 20;

    int* ptr2 = NULL;
    ptr2 = (int*)realloc(ptr, n * sizeof(int));
    //ptr = (int*)realloc(ptr, n * sizeof(int));

    printf("%p %p\n",ptr, ptr2);

    printf("%d\n", ptr[0]);

    if (!ptr2)
        exit(1);
    else
        ptr = NULL;

    for (int i = 0; i < n; ++i) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    free(ptr2);


    return 0;
}