#include <stdio.h>
#include <stdlib.h>

int main() {
    // int row = 3, col = 2;
    // int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);    // 상수를 사용할 수 밖에 없으므로 비효율적.
    // //int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);  //VLA
    // if (!ptr2d) exit(1);

    // for (int r = 0; r < row; r++) {
    //     for (int c = 0; c < col; c++) {
    //         ptr2d[r][c] = c + col * r;
    //     }
    // }

    // for (int r = 0; r < row; r++) {
    //     for (int c = 0; c < col; c++) {
    //         printf("%d ", ptr2d[r][c]);
    //     }
    //     printf("\n");
    // }


    /*
        2d array.
    */

    // int row = 3, col = 2;
    // int* ptr =  (int*)malloc(sizeof(int) * row * col);
    // if (!ptr) exit(1);

    // for (int r = 0; r < row; r++) {
    //     for (int c = 0; c < col; c++) {
    //         ptr[r * col + c] = r * col + c;
    //     }
    // }

    // for (int r = 0; r < row; r++) {
    //     for (int c = 0; c < col; c++) {
    //         printf("%d ", ptr[r * col + c]);
    //     }
    //     printf("\n");
    // }



    /*
        3d array.
    */

    int row = 3, col = 2, depth = 2;

    int* ptr = (int*)malloc(sizeof(int) * row * col * depth);
    if (!ptr) exit(1);

    for (int d = 0; d < depth; d++) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                ptr[c + (col * r) + (col * row) * d] = c + (col * r) + (col * row) * d;
            }
        }
    }

    /*
        int idx2(int c, int r) {
            return c + col * r;
        }

        int idx3(int c, int r, int d) {
            static const int cr = col * row;
            return c + col * r + cr * d;
        }
    */

    for (int d = 0; d < depth; d++) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                printf("%d ", *(ptr + c + 
                col * r + (col * row) * d));
            }
            printf("\n"); 
        }
        printf("\n");
    }

    return 0;
}