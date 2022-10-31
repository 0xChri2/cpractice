#include <stdio.h>

int main() {
#define SIZE 3

    int matrix_a [SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix_b [SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix_c [SIZE][SIZE];

    for(int i = 0;i < SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int l = 0; l < SIZE; l++) {
                matrix_c[i][j] += matrix_a[i][l] * matrix_b[l][j];
            }
        }
    }
    for(int t = 0;t< SIZE;t++){
        for(int k = 0;k < SIZE;k++){
            printf("%d ", matrix_c[t][k]);
        }
        printf("\n");
    }
    return 0;
}

