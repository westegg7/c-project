#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int ch;
    FILE* fr, * fw;

    const char* file_out = "copy_input";

    if (argc != 2) {
        printf("Usage %s", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fr = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fw = fopen(file_out, "w")) == NULL) {
        printf("Can't open %s", file_out);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fr)) != EOF) {
        fputc(ch, stdout);
        fputc(ch, fw);
    }

    fclose(fr);
    fclose(fw);

    return 0;
}