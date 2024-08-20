#include <stdio.h>

#define TAMANHO 2

void multiplica_matrizes(int mat1[TAMANHO][TAMANHO], int mat2[TAMANHO][TAMANHO], int resultado[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < TAMANHO; k++) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[TAMANHO][TAMANHO] = {
        {1, 2},
        {3, 4}
    };

    int mat2[TAMANHO][TAMANHO] = {
        {5, 6},
        {7, 8}
    };

    int resultado[TAMANHO][TAMANHO];

    multiplica_matrizes(mat1, mat2, resultado);

    printf("A matriz resultante da multiplicação é:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
