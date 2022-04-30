#include <stdio.h>

int main() {
    enum spectrum { red, orange, yellow, green, blue, violet };

    enum spectrum color;
    color = blue;
    if (color == yellow)
        printf("yellow");   // Note: enumerators are not strings

    for (color = red; color <= violet; color++) //Note: ++ operator doesn't allowed in C++
        printf("%d\n", color);

    printf("\n");

    enum levels { low = 100, medium = 500, high = 1000 };

    int score = 900;
    if (score > high)
        printf("High Score!\n");
    else if (score > medium)
        printf("Good job\n");
    else if (score > low)
        printf("Not bad\n");
    else
        printf("Suck!\n");

    enum pet { cat, dog = 10, lion, tiger};

    printf("cat %d\n", cat);
    printf("lion %d\n", lion); 


    return 0;
}