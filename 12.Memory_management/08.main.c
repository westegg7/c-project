#include <stdio.h>

/*
    Static variable with external linkage
    - File scope, external linkage, static storage duration
    - External storage class
    - External variables
*/

int g_int = 0;
// int g_int = 7;   //Error. 초기화는 단 한 번만.
double g_arr[1000] = { 0.0, };

/*
    Initializing External Variables 
*/
int x = 5;
int y = 1 + 2;

void fun_sec();

int main() {
    /*
        defining declaration vs referencing declaration
    */

    extern int g_int;           // optional. 파일스코프에 있는 식별자를 쓸것. 명확하게 표시. 
    // extern int g_int = 1024;  // 초기화 Error in block scope.  

    // int g_int = 123; //hides global g_int. 
    //global var의 hiding을 방지하기 위해 위에서 extern을 붙임.

    extern double g_arr[];  //optional, size is not necessary. 위에서 사이즈는 결정됨.

    printf("g_int in main() %d %p\n", g_int, &g_int);
    g_int++;

    fun_sec();


    return 0;
}