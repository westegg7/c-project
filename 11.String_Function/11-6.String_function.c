#include <stdio.h>
#include <string.h>

void fit_str(char* str, unsigned int n);
char* my_strcat(char* str1, const char* str2);
int my_strcmp(const char* str1, const char* str2);
char* my_strcpy(char* dest, const char* source);

int main() {  
    /*
        strlen() %lu
    */
    // char msg[] = "Just,"" do it!";
    // puts(msg);
    // printf("Length %lu\n", strlen(msg));
    // fit_str(msg, 4);
    // puts(msg);
    // printf("Length %lu\n",strlen(msg));



    /*
        strcat() and strncat() : string concatenation
    */
    
    // char str1[100] = "First string";    // 첫번째 문자열은 충분한 공간이 필요. 뒤에 덧붙여야하기 때문
    // char str2[] = "Second string";

    // my_strcat(str1, str2);
    // strcat(str1, ", ");
    // strcat(str1, str2);
    // strncat(str1, str2, 3);
    // puts(str1);



    /*
        strcmp() and strncmp() : compare strings (not characters)
    */

    // printf("%d\n", my_strcmp("A", "A"));   // return 0
    // printf("%d\n", my_strcmp("A", "B"));   // return -1 : 아스키코드 상으로 A의 값이 작음
    // printf("%d\n", my_strcmp("B", "A"));   // return 1 : 아스키코드 상으로 B의 값이 큼
    // printf("%d\n", my_strcmp("Hello", "Hello"));
    // printf("%d\n", my_strcmp("Banana", "Bananas"));    // return -1 : s보다 '\0'이 앞에 있음.
    // printf("%d\n", my_strcmp("Bananas", "Banana"));
    // printf("%d\n", strncmp("Bananas", "Banana", 6));
    // //TODO : implement strcmp!


    /*
        strcpy() and strncpy()
    */

    // char dest[100]; //make sure memory is enough
    // char source[] = "Start programming!";
    // my_strcpy(dest, source);
    // strncpy(dest, source, 5);   // '\0' is NOT added!!!
    // my_strcpy(dest, source + 6);
    // my_strcpy(dest, source);
    // my_strcpy(dest + 6, "coding!");
    // puts(dest);


    /*
        sprintf()
    */

    // char str[100];
    // int i = 123;
    // double d = 3.14;
    // sprintf(str, "%05d.png %f", i, d);
    // puts(str);
    // // capture00000.png, capture00001.png, ...


    /*
        There are more functions...
    */
    // // 모두 포인터를 반환하는 함수다. 
    
    // printf("%s\n", strchr("Hello World", 'W')); // W부터 '\0'까지

    // printf("%s\n", strpbrk("Hello, World", "ABCDE"));
    // printf("%s\n", strpbrk("Hello, World", "abcde"));

    // printf("%s\n", strrchr("Hello, World, Hello, World", 'l')); // last occurrence
    
    // printf("%s\n", strstr("Hello, World", "wor"));
    // printf("%s\n", strstr("Hello, World", "Wor"));

    return 0;
}

void fit_str(char* str, unsigned int n) {
    if (strlen(str) > n)
        str[n] = '\0';
}

char* my_strcat(char* str1, const char* str2) {
    // while (*str1 != '\0')    // 반복문을 2개나 쓰므로 비효율적. 밑의 코드가 더 좋다. 
    // {
    //     str1++;
    // }
    // while (*str2 != '\0')
    // {
    //     *str1++ = *str2++;
    // }


    char* ptr = str1 + strlen(str1);

    while (*str2 != '\0') {
        *ptr++ = *str2++;   // 후위 증가 연산자 우선순위 > 포인터 우선순위.
    }

    *ptr = '\0';

    return str1;
}

int my_strcmp(const char* str1, const char* str2) {
	
	while (1) {
		if ((int)(*str1) > (int)(*str2))
			return 1;
		else if ((int)(*str1) < (int)(*str2))
			return -1;
		else {
			if (*str1 == '\0' && *str2 == '\0')
				return 0;
		}
		str1++;
		str2++;
	}
    return 0;
}

char* my_strcpy(char* dest, const char* source) {
    if (dest == NULL) {
        return NULL;
    }

    char *ptr = dest;

    while (*source) {
        *dest++ = *source++;
    }
    *dest = '\0';

    return ptr;
}