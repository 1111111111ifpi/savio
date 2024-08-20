#include <stdio.h>

int main() {
    int troco = 68;  // Valor do troco em centavos
    int moedas = 0;  // Contador de moedas usadas

    // Calcula o número de moedas de 25 centavos necessárias
    moedas += troco / 25;  // Adiciona o número de moedas de 25 centavos
    troco %= 25;  // Atualiza o valor do troco restante

    // Calcula o número de moedas de 10 centavos necessárias
    moedas += troco / 10;  // Adiciona o número de moedas de 10 centavos
    troco %= 10;  // Atualiza o valor do troco restante

    // Calcula o número de moedas de 5 centavos necessárias
    moedas += troco / 5;  // Adiciona o número de moedas de 5 centavos
    troco %= 5;  // Atualiza o valor do troco restante

    // Calcula o número de moedas de 1 centavo necessárias
    moedas += troco;  // O que sobrar é o número de moedas de 1 centavo

    // Imprime o número total de moedas usadas
    printf("%d\n", moedas);

    return 0;
}
