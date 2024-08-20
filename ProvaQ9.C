#include <stdio.h>
#include <string.h>

// Função para determinar o resultado do jogo entre Sheldon e Raj
const char* determinar_resultado(const char* sheldon, const char* raj) {
    // Se Sheldon e Raj escolherem a mesma coisa, o resultado é um empate
    if (strcmp(sheldon, raj) == 0) {
        return "De novo!";
    }
    
    // Condições para Sheldon vencer o jogo
    if ((strcmp(sheldon, "tesoura") == 0 && (strcmp(raj, "papel") == 0 || strcmp(raj, "lagarto") == 0)) ||
        (strcmp(sheldon, "papel") == 0 && (strcmp(raj, "pedra") == 0 || strcmp(raj, "spock") == 0)) ||
        (strcmp(sheldon, "pedra") == 0 && (strcmp(raj, "lagarto") == 0 || strcmp(raj, "tesoura") == 0)) ||
        (strcmp(sheldon, "lagarto") == 0 && (strcmp(raj, "papel") == 0 || strcmp(raj, "spock") == 0)) ||
        (strcmp(sheldon, "spock") == 0 && (strcmp(raj, "tesoura") == 0 || strcmp(raj, "pedra") == 0))) {
        return "Bazinga!"; // Sheldon vence
    }
    
    // Caso contrário, Raj vence
    return "Raj trapaceou!";
}

int main() {
    int T;
    
    // Lê o número de casos de teste
    scanf("%d", &T);
    
    // Itera sobre cada caso de teste
    for (int t = 1; t <= T; t++) {
        char sheldon[20], raj[20];
        
        // Lê as escolhas de Sheldon e Raj
        scanf("%s %s", sheldon, raj);
        
        // Determina o resultado do jogo entre Sheldon e Raj
        const char* resultado = determinar_resultado(sheldon, raj);
        
        // Exibe o resultado para o caso atual
        printf("Caso #%d: %s\n", t, resultado);
    }
    
    return 0;
}
