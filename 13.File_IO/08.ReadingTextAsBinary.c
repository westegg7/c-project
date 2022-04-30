#include <stdio.h>

int main() {
    FILE* fp = fopen("test", "rb");

    unsigned char ch;

    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)
        printf("%hhu %c\n",ch, ch);

    fclose(fp);

    return 0;
}

/*
    텍스트파일 내용
    XYZ
    123
    C언어
    안녕
    
    알파벳이나 숫자등의 아스키코드는 1바이트를 사용. 한글은 3바이트를 사용함을 알 수 있다. 
    
    OS에 따른 개행문자의 차이
    CRLF - 윈도우
    LF - 리눅스, 맥
*/