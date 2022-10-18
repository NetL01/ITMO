#include <stdio.h>

int main() {
    int a[7] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int matrix1[2][2] = {1, 1,
                         1, 4};
    int matrix2[2][2] = {1, 2,
                         4, 1};
    int matrix_result[2][2] = {0, 0,
                               0, 0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int result = 0;
            for (int k = 0; k < 2; k++) {
                result += matrix1[i][k] * matrix2[k][j];
                matrix_result[i][j] = result;
            }
            printf("%d ", result);
        }
        printf("\n");
    }

    return 0;
}