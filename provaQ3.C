#include <stdio.h>
#include <cs50.h> 

// Função que conta o número de dígitos de um número long
int numero_de_digitos(long numero) {
    int contagem = 0;
    // Loop para dividir o número por 10 repetidamente até que seja zero
    while (numero > 0) {
        numero /= 10;
        contagem++;
    }
    return contagem;
}

// Função que verifica se o número do cartão é válido usando o algoritmo de Luhn
bool e_valido(long numero) {
    int soma = 0;
    bool dobrar = false;  // Indica se o dígito deve ser dobrado

    // Loop para processar cada dígito do número
    while (numero > 0) {
        int digito = numero % 10;  // Obtém o último dígito do número
        numero /= 10;  // Remove o último dígito

        // Se for para dobrar o dígito
        if (dobrar) {
            digito *= 2;
            // Se o resultado da multiplicação for maior que 9, subtrai 9
            if (digito > 9) {
                digito -= 9;
            }
        }
        soma += digito;  // Adiciona o dígito (ou o ajustado) à soma
        dobrar = !dobrar;  // Alterna o valor de "dobrar" para o próximo dígito
    }
    // O número é válido se a soma for divisível por 10
    return (soma % 10 == 0);
}

// Função que determina o tipo de cartão de crédito com base nos dígitos e tamanho
void determinar_tipo(long numero) {
    int digitos = numero_de_digitos(numero);  // Conta o número de dígitos

    // Verifica se é um American Express (AMEX)
    if (digitos == 15 && (numero / 10000000000000 == 34 || numero / 10000000000000 == 37)) {
        printf("AMEX\n");
    }
    // Verifica se é um MasterCard
    else if (digitos == 16 && (numero / 1000000000000000 == 51 || numero / 1000000000000000 == 52 ||
                               numero / 1000000000000000 == 53 || numero / 1000000000000000 == 54 ||
                               numero / 1000000000000000 == 55)) {
        printf("MASTERCARD\n");
    }
    // Verifica se é um Visa
    else if ((digitos == 13 || digitos == 16) && 
             (numero / 1000000000000 == 4 || numero / 1000000000000000 == 4)) {
        printf("VISA\n");
    }
    // Se não corresponder a nenhum dos tipos conhecidos, é inválido
    else {
        printf("INVALID\n");
    }
}

int main() {
    // Solicita o número do cartão de crédito ao usuário
    long numero = get_long("Número do cartão de crédito: ");

    // Verifica se o número do cartão é válido
    if (e_valido(numero)) {
        determinar_tipo(numero);  // Se for válido, determina o tipo de cartão
    } else {
        printf("INVALID\n");  // Se não for válido, imprime "INVALID"
    }

    return 0;
}
