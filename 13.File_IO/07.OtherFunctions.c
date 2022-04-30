#include <stdio.h>

int main() {
    FILE* fp;
    int ch;

    /* ungetc() */
    fp = fopen("input", "r");

    ch = fgetc(fp);
    fputc(ch, stdout);

    ungetc(ch, fp); // 읽어들인 글자를 다시 버퍼에(파일X) 넣는다. 

    ch = fgetc(fp);
    fputc(ch, stdout);

    ch = fgetc(fp);
    fputc(ch, stdout);

    fclose(fp);

    printf("\n\n");

    /* setvbuf() */

    fp = fopen("input", "r");

    char buffer[32] = {'\0', };

    setvbuf(fp, buffer, _IOFBF, sizeof(buffer));    // _IOLBF, _IOFBF, _IONBF, 차례대로 Line, Full, No.

    // dump buffer
    for (int i = 0; i < sizeof(buffer); ++i)
        printf("%hhd", buffer[i]);
    printf("\n");

    ch = fgetc(fp); // Read just only a single character!   

    // dump buffer
    for (int i = 0; i < sizeof(buffer); ++i)
        printf("%c", buffer[i]);
    printf("\n");

    fclose(fp);


    /* fflush() */

    // Writing a large amount of data
    // fflush(fp);

    return 0;
}

/* 
    ungetc()
    setvbuf()
    fflush()

    버퍼의 작동원리. fgetc()함수로 하나의 문자만 읽어왔지만 버퍼에는 미리 모든값이 들어와있다.
*/