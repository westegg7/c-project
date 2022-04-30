#include <stdio.h>

/*
    Storage duration:
    - static storage duration   계속 메모리에 있는다
    (Note: 'static' keyword indicates the linkage type, not the storage duration)
    - automatic storage duration    스택에 저장 - 스코프에 따라 지속
    - allocated storage duration    동적할당관련
    - thread storage duration   멀티스레딩 관련
*/


void count() {
    int ct = 0;
    printf("count = %d\n", ct);
    ct++;
}

void static_count() {
    static int ct = 0;  //프로그램 종료때까지 메모리에 유지.
    printf("static count = %d\n", ct);
    ct++;
}

int main() {
    count();
    count();
    static_count();
    static_count();

    return 0;
}