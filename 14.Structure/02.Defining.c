#include <stdio.h>
#include <string.h>

#define MAX 41

struct person   //
{
    char name[MAX]; // member. 여기서는 멤버선언만 되고 변수가 선언될때 비로소 메모리가 할당된다. 
    int age;        // member. 초기화 안됨.
    float height;   // member.
    float weight;   // member.
};

int main() {
    int flag;

    struct person genie;    // 이때 메모리 할당됨

    strcpy(genie.name, "Will Smith");
    genie.age = 1000;
    genie.height = 198;

    flag = scanf("%f", &genie.weight);
    printf("%f\n", genie.height);

    /* Initialization */

    struct person princess = {
        "Naomi Scott",
        21,
        170.0f,
        40.0f 
    };

    /* Designated initializers */

    struct person beauty = {
        .name = "Bell",
        .age = 16,
        .weight = 40.0f,
        .height = 165.0f
    };

    
    /* Pointer to a structure variable */

    struct person* someone;

    someone = &genie;

    someone->age = 1001;
    printf("%s %d\n", someone->name, (*someone).age);

    struct {
        char farm[MAX];
        float price;
    } apple, apple2;        // 일시적으로 사용할 구조체의 경우 이렇게 이름이 없이 사용도 가능. 같은 구조체로 변수를 선언하고 싶으면 구조체도 다시 선언해야함.


    /* typedef and structure */

    typedef struct person my_person;   //my_person 이라는 자료형이 있는 것처럼 사용 가능. 

    my_person p3;

    typedef struct person person;   

    person p4;


    typedef struct {
        char name[MAX];
        char hobby[MAX];
    } friend;

    friend f4;      // 이 용법도 많이 쓰인다.




    return 0;
}