#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    //char* title;      // Not Recommend
    //char* author;     // Not Recommend
    float price;
};

struct rectangle {
    double width;
    double height;
};

double rect_area(struct rectangle r) {
    return r.width * r.height;
}

double rect_area_pt(struct rectangle* r) {
    return r->height * r->width;
}

int main() {
    struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };

    /*
        Compound literals
        - Temporary structure values
    */

    // book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f }; // 문법적으로 초기화는 한번만 가능

    strcpy(book_to_read.title, "Alice in Wonderland");
    strcpy(book_to_read.author, "Lewis Carroll");
    book_to_read.price = 20.3f;

    // or

    struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
    book_to_read = book2;

    // or

    book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };
    //중요!! (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f } 는 L-value다!!!

    printf("%s %s\n", book_to_read.title, book_to_read.author);

    struct rectangle rec1 = { 1.0, 2.0 };
    double area = rect_area(rec1);      // 이경우에는 rec1라는 변수생성이 필요. 


    double area2 = rect_area((struct rectangle) {1.0, 2.0});

    area2 = rect_area_pt(&(struct rectangle){ .width = 3.0, .height = 4.0 });

    printf("%f", area2);

    return 0;
}


/*
    구조체를 초기화하고 값을 바꿔서 사용하고 싶을때
    멤버의 값을 하나하나 바꾸거나, 새로운 구조체 변수를 만들고 그 값을 복사하는 것은 번거롭다.

    (struct 구조체 이름){ "초기화값", 초기화값, ...} 이런식으로 재초기화가 가능하다.
    여기서 (struct 구조체 이름){ "초기화값", 초기화값, ...} 자체가 메모리를 가지는 L-value 이므로
    따로 구조체 변수를 만들지 않고 그 자체로 함수의 인수로서 사용할 수도 있고 주소를 가져올 수도 있다.
*/