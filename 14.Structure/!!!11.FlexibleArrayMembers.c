#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        Flexible array member (struct hack in GCC)
    */

    struct flex {
        size_t count;   // size_t 는 32비트에서 4바이트, 64비트에선 8바이트다.
        double average;
        double values[];    // flexible array member (반드시 마지막 멤버로 와야함.)
    };
    // double values[] (사이즈0 배열) VS double* values(포인터 변수)
    // values[]는 따로 메모리를 차지하지 않는다. average 변수 뒤에 일렬로 나열된 메모리를 차지한다.
    // double* values 형태라면 포인터변수로서 메모리를 차지한다. 메모리 상의 위치가 정확하지 않다.

    const size_t n = 3; // n값만 바꾸면 동적메모리의 크기를 편리하게 바꿀 수 있다.

    struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
    if (pf == NULL) exit(1);

    printf("\nFlexible array member\n");
    printf("Sizeof struct flex %zd\n", sizeof(struct flex));    // 16
    printf("Size of *pf %zd\n", sizeof(*pf));                   // 16
    printf("Size of malloc %zd\n\n", sizeof(struct flex) + n * sizeof(double));   // 40

    printf("%lld\n", (long long)pf);
    printf("%lld\n", (long long)& pf->count);
    printf("%zd\n", sizeof(pf->count));
    printf("%lld\n", (long long)& pf->average);
    printf("Address of pf->values %lld\n", (long long)& pf->values);
    printf("Value of pf->values %lld\n", (long long)pf->values);
    // printf("Sizeof pf->values %zd\n", sizeof(pf->values));


    /* 사용례 */

    pf->count = n;
    pf->values[0] = 1.1;
    pf->values[1] = 2.1;
    pf->values[2] = 3.1;

    pf->average = 0.0;
    for (unsigned i = 0; i < pf->count; ++i)
        pf->average += pf->values[i];
    pf->average /= (double)pf->count;

    printf("Average = %f\n", pf->average);



    /*
        struct nonflex {
            size_t count;
            double average;
            double *values;     // Use malloc()
        };

    struct nonflex nf;
    nf.value = (double*)malloc(sizeof(double) * n);
    */

/*
    struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
    if (pf2 == NULL) exit(1);

    *pf2 = *pf1     //Don't copy flexible members, use mamcpy() instead.

    // 동적할당받은 배열을 제외한 멤버만 복사됨. 동적할당받은 메모리에 대해서는 컴파일러가 알 수 없다.
    // memcopy() 를 통해서 (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double)) 전체를 복사해야한다.
*/

    return 0;
}