#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Função para validar a chave fornecida
int is_valid_key(const char *key) {
    // Verifica se a chave tem exatamente 26 caracteres
    if (strlen(key) != 26) {
        return 0; 
    }

    int freq[26] = {0}; // Array para contar a frequência de cada letra

    // Itera sobre cada caractere da chave
    for (int i = 0; i < 26; i++) {
        // Verifica se o caractere é uma letra
        if (!isalpha(key[i])) {
            return 0; 
        }

        // Converte a letra para maiúscula
        char c = toupper(key[i]);

        // Verifica se a letra já apareceu na chave
        if (freq[c - 'A'] > 0) {
            return 0; 
        }
        // Marca a letra como vista
        freq[c - 'A']++;
    }
    return 1; // A chave é válida
}

int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos é igual a 2 (programa + chave)
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Verifica se a chave fornecida é válida
    if (!is_valid_key(argv[1])) {
        printf("Invalid key\n");
        return 1;
    }

    // Copia a chave para um array e converte para maiúsculas
    char key[26];
    for (int i = 0; i < 26; i++) {
        key[i] = toupper(argv[1][i]);
    }

    // Mapeia as letras do alfabeto para a chave fornecida
    char map[26];
    for (int i = 0; i < 26; i++) {
        map[i] = key[i];
    }

    // Solicita o texto em claro do usuário
    printf("Plaintext: ");
    char plaintext[1000]; 
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    // Remove o caractere de nova linha '\n' no final da string
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Imprime o texto cifrado
    printf("Ciphertext: ");
    for (size_t i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            // Determina a base (A para maiúsculas, a para minúsculas)
            char base = isupper(c) ? 'A' : 'a';
            // Mapeia o caractere e preserva o caso
            printf("%c", isupper(c) ? map[c - 'A'] : tolower(map[c - 'a']));
        } else {
            // Se não for uma letra, imprime o caractere como está
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
