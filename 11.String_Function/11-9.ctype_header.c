#include <stdio.h>
#include <string.h>
#include <ctype.h>  // islower(), toupper(), ispunct()

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main() {
    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);  // fgets() 는 '\n'을 포함한다. 이것을 '\0'으로 바꾸어야한다.
    new_line = strchr(line, '\n');  // find first newline. strchr() returns pointer.
    if (new_line)
        *new_line = '\0';

    ToUpper(line);
    puts(line);
    printf("%d\n", PunctCount(line));

    return 0;
}

void ToUpper(char* str) {
    while (*str) {
        if (islower((int)*str)){
            *str = toupper((int)*str);
        }
        str++;
    }
}
int PunctCount(const char* str) {
    int count = 0;

    while (*str) {
        if (ispunct((int)*str)) {
            count++;
        }
        str++;
    }

    return count;
}
