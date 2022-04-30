#include <stdio.h>

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main() {
    int arr[] = { 2, 25, 12, 22, 11, 100, 51, 33, 8, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);   // ascending order

    printArray(arr, n);


    return 0;
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
void selectionSort(int arr[], int n) {
    int min_idx;    // 값이 가장 작은 배열 원소의 인덱스

    for (int j = 0; j < n - 1; j++){
        min_idx = j;
        for (int i = j + 1; i < n; i++) {
            if (arr[min_idx] > arr[i]) {
                min_idx = i;
            }
        }
        swap(&arr[j], &arr[min_idx]);
    }
}