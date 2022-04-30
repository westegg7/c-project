#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

#define LEN 30

int main() {
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;

    while (1) {
        printf("Input a color name (empty line to quit):\n");

        if (scanf("%[^\n]%*c", choice) != 1)        // empty line to quit
            break;
        
        for (color = red; color <= blue; color++) {
            if (strcmp(choice, colors[color]) == 0) {
                color_is_found = true;
                break;
            }
        }

        if (color_is_found)
            switch (color) {
                case red:
                    printf("Red Roses\n");
                    break;
                case orange:
                    printf("The Clockwise Orange\n");
                    break;
                case yellow:
                    printf("Yellow Submarine\n");
                    break;
                case green:
                    printf("Eva Green\n");
                    break;
                case blue:
                    printf("Blue Moon\n");
            }
        else
            printf("Please try different color %s.\n", choice);
        color_is_found = false;
    }
    puts("Bye!");

    return 0;
}
