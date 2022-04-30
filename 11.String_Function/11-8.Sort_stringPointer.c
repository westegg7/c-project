#include <stdio.h>
#include <string.h> // strcmp()

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {
    char* arr[] = { "Apple", "Google", "Facebook", "Amazon", "Netflix" };   // 문자열 "포인터"의 배열
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);

    printStringArray(arr, n);

    return 0;
}

void swap(char** xp, char** yp) {
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printStringArray(char* arr[], int size) {
    for (int i = 0; i < size; i++) {
        puts(arr[i]);
    }
    printf("\n");
}
void selectionSort(char* arr[], int n) {
    int min_idx;
    int i, j;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}