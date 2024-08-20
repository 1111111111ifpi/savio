#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Função que verifica se uma string contém apenas dígitos
int is_digit_string(const char *str) {
    // Percorre a string até o final
    for (int i = 0; str[i] != '\0'; i++) {
        // Se encontrar algum caractere que não seja um dígito, retorna 0 (falso)
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1; // Se todos os caracteres forem dígitos, retorna 1 (verdadeiro)
}

int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos é exatamente 2 (programa + chave)
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Verifica se a chave fornecida é uma string de dígitos
    if (!is_digit_string(argv[1])) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Converte a chave de string para um número inteiro
    int key = atoi(argv[1]);

    // Solicita ao usuário que insira o texto em claro
    printf("Plaintext: ");
    char plaintext[1000];
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    // Remove o caractere de nova linha '\n' do final da string, se presente
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Gera e imprime o texto cifrado
    printf("Ciphertext: ");
    for (size_t i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        // Verifica se o caractere é uma letra
        if (isalpha(c)) {
            // Determina a base ('A' para maiúsculas, 'a' para minúsculas)
            char base = isupper(c) ? 'A' : 'a';
            // Aplica a cifra de César com a chave dada
            printf("%c", (c - base + key) % 26 + base);
        } else {
            // Se não for uma letra, imprime o caractere como está
            printf("%c", c);
        }
    }
    printf("\n");

    return 0; // Indica que o programa terminou com sucesso
}
