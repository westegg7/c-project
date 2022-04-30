#include <stdio.h>
#include <stdlib.h>

int main() {
    int ch;
    FILE* fr, * fw;

    const char* in_filename = "원본";
    const char* out_filename = "사본";

    unsigned long count = 0;

    if ((fr = fopen(in_filename, "r")) == NULL) {
        printf("Can't open %s", in_filename);
        exit(EXIT_FAILURE);
    }

    if ((fw = fopen(out_filename, "w")) == NULL) {
        printf("Can't open %s", out_filename);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fr)) != EOF) {
        fputc(ch, stdout);
        fputc(ch, fw);
        count++;
    }

    fclose(fr);
    fclose(fw);

    printf("FILE %s has %lu characters\n", in_filename, count);

    return 0;
}