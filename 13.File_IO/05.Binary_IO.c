#include <stdio.h>
#include <stdlib.h>

int main() {
    {
        FILE* fp = fopen("binary_file", "wb");

        double d = 1.0 / 3.0;
        int n = 100;
        int* parr = (int*)malloc(sizeof(int) * n);
        if (!parr) exit(1);
        for (int n = 0; n < 100; ++n)
            parr[n] = n * 2;

        fwrite(&d, sizeof(d), 1, fp);
        fwrite(&n, sizeof(n), 1, fp);
        fwrite(parr, sizeof(int), n, fp);

        fclose(fp);
        free(parr);
    }

// Reading example, feof(), ferror()
    {
        FILE* fp = fopen("binary_file", "rb");
        
        double d;
        int n = 0;
        fread(&d, sizeof(d), 1, fp);
        fread(&n, sizeof(n), 1, fp);    // n 을 먼저 읽고 parr을 할당해야 한다.

        int* parr =  (int*)malloc(sizeof(int) * n); // 서비스의 접속자, 회원 등이 실시간으로 바뀌는 경우, 동적할당 사용.
        if (!parr) exit(1);

        fread(parr, sizeof(int), n, fp);

        printf("feof = %d\n", feof(fp));

        printf("%f\n", d);
        printf("%d\n", n);
        for (int i = 0; i < n; ++i) 
            printf("%d ", *(parr + i));
        printf("\n");

        printf("feof = %d\n", feof(fp));

        fread(&n, sizeof(n), 1, fp);            // read one more toward EOF

        printf("feof = %d\n", feof(fp));        // return non-zero at EOF
        printf("ferror = %d\n", ferror(fp));    // return 0 : ok

        fwrite(&n, sizeof(n), 1, fp);           // try writing

        printf("ferror = %d\n", ferror(fp));    // 0 is ok, non-zero otherwise.
    
        fclose(fp);
        free(parr);
    }

    return 0;
}