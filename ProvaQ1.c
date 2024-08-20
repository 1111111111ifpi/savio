#include <stdio.h>

int main()
{
int soma = 1;
int tamanho = 0;
int resultado;

int soma_array(int array[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

int main() {
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int array[n];

    printf("Digite os %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int resultado = soma_array(array, n);

    printf("A soma dos elementos do array é: %d\n", resultado);

    return 0;
}

  
}




