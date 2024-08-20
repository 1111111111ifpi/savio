#include <stdio.h>

// Define uma constante para o tamanho das matrizes
#define TAMANHO 2

// Função para multiplicar duas matrizes quadradas de tamanho TAMANHO x TAMANHO
void multiplica_matrizes(int mat1[TAMANHO][TAMANHO], int mat2[TAMANHO][TAMANHO], int resultado[TAMANHO][TAMANHO]) {
    // Itera sobre as linhas da primeira matriz
    for (int i = 0; i < TAMANHO; i++) {
        // Itera sobre as colunas da segunda matriz
        for (int j = 0; j < TAMANHO; j++) {
            // Inicializa o elemento da matriz resultante com 0
            resultado[i][j] = 0;
            // Realiza a multiplicação e soma dos elementos correspondentes
            for (int k = 0; k < TAMANHO; k++) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    // Define e inicializa a primeira matriz
    int mat1[TAMANHO][TAMANHO] = {
        {1, 2},
        {3, 4}
    };

    // Define e inicializa a segunda matriz
    int mat2[TAMANHO][TAMANHO] = {
        {5, 6},
        {7, 8}
    };

    // Define uma matriz para armazenar o resultado da multiplicação
    int resultado[TAMANHO][TAMANHO];

    // Chama a função para multiplicar as matrizes
    multiplica_matrizes(mat1, mat2, resultado);

    // Exibe a matriz resultante
    printf("A matriz resultante da multiplicação é:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
