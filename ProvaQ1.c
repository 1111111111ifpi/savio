#include <stdio.h>

// Função que calcula a soma dos elementos de um array
int soma_array(int array[], int tamanho) {
    int soma = 0; // Inicializa a soma em 0
    // Percorre todos os elementos do array e os soma
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma; // Retorna a soma total
}

int main() {
    int n; // Variável para armazenar o tamanho do array

    // Solicita ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Declara um array com o tamanho fornecido pelo usuário
    int array[n];

    // Solicita ao usuário que insira os elementos do array
    printf("Digite os %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]); // Lê cada número inteiro para o array
    }

    // Chama a função para calcular a soma e armazena o resultado
    int resultado = soma_array(array, n);

    // Exibe o resultado da soma
    printf("A soma dos elementos do array é: %d\n", resultado);

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}




