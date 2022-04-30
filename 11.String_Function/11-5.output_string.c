#include <stdio.h>

#define TEST "A String from #define"

void custom_put(const char* str);   // Only two lines
int custom_put2(const char* str);   // Add \n, return # of characters

int main()
{
    // char str[60] =  "String array initialized";
    // const char* ptr = " A pointer initialized";

    // puts("String without \\n"); // puts function adds '\n'
    // puts("END");
    // puts(TEST);
    // puts(TEST + 5);
    // puts(&str[3]);
    // // puts(str[3]); //Error
    // puts(ptr + 3);


    // char str[] = { 'H', 'I', '!' }; // No \0 at the end
    // puts(str);


    // char line[100];
    // while(gets(line))
    //     puts(line);

    // char line[100];
    // while(fgets(line, 81, stdin))
    //     fputs(line, stdout);


    // char input[100]; 
    // int ret = scanf("%10s", input); //Input : "Just do it, do it!\n"  공백에서 읽기를 멈춤. 
    // printf("%s\n", input);
    // ret = scanf("%10s", input); //버퍼에 있는 나머지를 읽음. 공백 전까지.
    // printf("%s\n", input);


    /*
        Custom function
    */

    
    custom_put("Just ");
    custom_put("do it!");

    printf("%d\n", custom_put2("12345"));



    return 0;
}

void custom_put(const char* str)   // Only two lines
{
    while (*str)
        putchar(*str++);
}

int custom_put2(const char* str)   // Add \n, return # of characters
{
    int num = 0;

    while (*str != '\0')
    {
        putchar(*str++);
        num++;
    }
    
    putchar('\n');

    return num;
}