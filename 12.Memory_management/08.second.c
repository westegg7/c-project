#include <stdio.h>

extern int g_int;   // 파일스코프에서 초기화는 한번만 가능. 
//extern이 붙은쪽은 초기화를 피하는것이 편함.

void temp() {
    g_int += 1000;
}

void fun_sec() {
    temp();
    
    extern int g_int;   //함수스코프에서는 초기화불가
    // 전역변수는 데이터세그먼트 또는 BSS에 있고 함수는 스택프레임.
    g_int += 7;
    printf("g_int in fun_sec() %d %p", g_int, &g_int);

}