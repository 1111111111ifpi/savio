#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função que calcula a pontuação de uma palavra
int calcular_pontuacao(const char *palavra) {
    int pontuacao = 0;

    // Array com os valores das letras de A a Z
    int valores[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 
        1, 4, 4, 8, 4, 10
    };

    // Itera sobre cada letra da palavra
    for (int i = 0; palavra[i] != '\0'; i++) {
        // Converte a letra para maiúscula
        char letra = toupper(palavra[i]);

        // Verifica se a letra está no intervalo A-Z
        if (letra >= 'A' && letra <= 'Z') {
            // Calcula a pontuação baseada no valor da letra
            pontuacao += valores[letra - 'A'];
        }
    }
    
    return pontuacao; // Retorna a pontuação total
}

int main() {
    char palavra1[100], palavra2[100];

    // Pede ao Jogador 1 para inserir uma palavra
    printf("Jogador 1, insira sua palavra: ");
    fgets(palavra1, sizeof(palavra1), stdin);
    
    // Remove o caractere de nova linha '\n' inserido pelo fgets
    palavra1[strcspn(palavra1, "\n")] = '\0'; 

    // Pede ao Jogador 2 para inserir uma palavra
    printf("Jogador 2, insira sua palavra: ");
    fgets(palavra2, sizeof(palavra2), stdin);
    
    // Remove o caractere de nova linha '\n' inserido pelo fgets
    palavra2[strcspn(palavra2, "\n")] = '\0'; 
    
    // Calcula a pontuação das palavras inseridas pelos jogadores
    int pontuacao1 = calcular_pontuacao(palavra1);
    int pontuacao2 = calcular_pontuacao(palavra2);
    
    // Compara as pontuações e determina o vencedor
    if (pontuacao1 > pontuacao2) {
        printf("Jogador 1 venceu!\n");
    } else if (pontuacao2 > pontuacao1) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
    
    return 0; // Indica que o programa terminou com sucesso
}
