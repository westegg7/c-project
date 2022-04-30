#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        malloc() returns a void type pointer.
        void* : generic pointer // 순수한 주소 포인터 연산 불가.

        free() deallocates the memory
    */

    double *ptr = NULL;

    ptr = (double*)malloc(30 * sizeof(double)); // ptr 변수자체는 블록스코프(스택)!! 블록을 나가면 사라진다. 
    // 힙에는 메모리가 여전히 할당되어 있는데 블록을 나가면 포인터 변수는 없어지기 때문에 잃어버릴 수 있다. 포인터와 메모리를 동일시하면 안된다!!

    if (ptr == NULL) {
        puts("Memory allocation failed.");  //malloc()이 메모리 공간을 못받아올 경우 NULL을 리턴.

        /*
            exit(EXIT_FAILURE) is similar to return 1 IN main().
            exit(EXIT_SUCCESS) is similar to return 0 IN main().
        */

        exit(EXIT_FAILURE); //어떤 함수에서든 강제로 종료할 수 있다.
    }

    printf("Before free %p\n", ptr);

    free(ptr);  //no action occurs when ptr is NULL

    printf("After free %p\n", ptr); //의미 없는 주소값.

    ptr = NULL; // optional. 메모리 할당은 free가 되었는데 ptr은 여전히 주소를 가리키고 있으므로 해주는게 좋다.


    /* Dynamically allocated Array */

    int n = 5;
    // ... 런타임에서야 n의 값을 알 수 있는 경우에도 malloc 사용가능. 
    ptr = (double*)malloc(n * sizeof(double));

    if (ptr != NULL) {
        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);
        printf("\n");

        for (int i = 0; i < n; ++i) 
            *(ptr + i) = (double)i;
        
        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);
        printf("\n");
    }

    free(ptr);
    ptr = NULL;

    // VLA와의 차이 숙지. 

    return 0;
}