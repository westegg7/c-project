#include <stdio.h>
#include <string.h> // strlen(), strcmp()
#include <stdlib.h> // malloc(), free()
#define SLEN 81

struct namect {
    char* fname;
    char* lname;
    int letters;
};

void getinfo(struct namect*);           // allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);           // free memory when done

int main() {
    /*
        Dangerous Usage
    */

    struct namect p = { "Hyunwoo", "Han" };
    printf("%s %s\n", p.fname, p.lname);

    // int f1 = scanf("%[^\n]%*c", p.lname);   // 오류 발생. 리터럴에 쓰기를 시도했기 때문에.
    // printf("%s %s\n", p.lname, p.fname);

    /*
        Recommend Usage
    */

    // char buffer[SLEN];
    // int f2 = scanf("%[^\n]%*c", buffer);
    // p.fname = (char*)malloc(strlen(buffer) + 1);    // null 캐릭터 공간 확보
    // if (p.fname != NULL)
    //     strcpy(p.fname, buffer);
    // printf("%s %s\n", p.fname, p.lname);


    /*
        ex
    */

    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    

    return 0;
}

void getinfo(struct namect* user_name) {
    int flag;
    char buffer[SLEN];

    printf("Input your first name. \n>> ");
    flag = scanf("%[^\n]%*c", buffer);
    if (flag != 1)
        printf("Wrong input");
    else {
        user_name->fname = (char*)malloc(strlen(buffer) + 1);
        if (user_name->fname != NULL)
            strcpy(user_name->fname, buffer);
        else
            printf("Malloc() failed");
    }
    
    printf("Input your last name. \n>> ");
    flag = scanf("%[^\n]%*c", buffer);
    if (flag != 1)
        printf("Wrong input");
    else {
        user_name->lname = (char*)malloc(strlen(buffer) + 1);
        if (user_name->lname != NULL)
            strcpy(user_name->lname, buffer);
        else
            printf("Malloc() failed");
    }
}

void makeinfo(struct namect* user_name) {
    user_name->letters = strlen(user_name->fname) + strlen(user_name->lname);
}

void showinfo(const struct namect* user_name) {
    printf("Hi, %s %s, your name has %d letters.", 
        user_name->fname, user_name->lname, user_name->letters);
}
void cleanup(struct namect* user_name) {
    free(user_name->fname);
    free(user_name->lname);
}
