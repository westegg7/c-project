#include <stdio.h>
#include <stdlib.h>

#define MAX 31  // 30 char + NULL

int main(void) {
    FILE* fp;
    char words[MAX] = { '\0' };

    const char* filename = "record";

    if ((fp = fopen(filename, "r+")) == NULL) {
        fprintf(stderr, "Can't open \"%s\" file.\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
        fprintf(fp, "%s\n", words);

    // while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
    //     fputs(words, fp);

    rewind(fp);

    while (fscanf(fp, "%s", words) == 1)// 입력받는 아이템이 하나, != EOF 로 해도 동일.
        fprintf(stdout, "%s\n", words);

    // while (fgets(words, MAX, fp) != NULL)    //EOF check
    //     fputs(words, stdout);

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}