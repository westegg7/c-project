#include <stdio.h>
#include <stdlib.h>

int main() {
    // make a test binary file
    {
        FILE* fp = fopen("binary", "wb");
        for (int i = 0; i < 100; ++i) {
            double d = i * 1.11;
            fwrite(&d, sizeof(double), 1, fp);
        }
        fclose(fp);
    }

    // read

    FILE* fp = fopen("binary", "rb");
    long cur;
    double d;

    cur = ftell(fp);
    printf("Before reading : %ld\n", cur);

    fread(&d, sizeof(double), 1, fp);

    cur = ftell(fp);
    printf("After reading : %ld\n", cur);

    printf("%f\n", d);

    fread(&d, sizeof(double), 1, fp);
    printf("%f\n", d);

    cur = ftell(fp);
    printf("After reading : %ld\n", cur);

    fseek(fp, 792L, SEEK_SET);
    fread(&d, sizeof(double), 1, fp);
    printf("%f\n", d);

    fclose(fp);

    return 0;
}

/*
    ftell() 함수, fseek()함수의 쓰임을 파악한다. 
    
    파일위치지정자. 버퍼의 존재
*/