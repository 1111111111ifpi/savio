#include <stdio.h>
#include <math.h>

int main() {
    // Matriz de dados onde cada linha contém valores de comprimento, largura e percentual de uso do terreno
    double dados[][3] = {
        {8, 10, 20},
        {1, 10, 100},
        {10, 3, 100},
        {0, 0, 0}  // Linha de sentinela para marcar o fim dos dados
    };
    
    double comprimento, largura, percentual;
    
    // Itera sobre cada linha de dados até encontrar a linha de sentinela (0, 0, 0)
    for (int i = 0; dados[i][0] != 0 || dados[i][1] != 0 || dados[i][2] != 0; i++) {
        comprimento = dados[i][0];  // Obtém o comprimento da casa
        largura = dados[i][1];      // Obtém a largura da casa
        percentual = dados[i][2];   // Obtém o percentual de ocupação do terreno
        
        // Calcula a área da casa
        double area_casa = comprimento * largura;
        
        // Calcula a área total do terreno com base no percentual de ocupação
        double area_terreno = (area_casa * 100) / percentual;
        
        // Calcula o lado do terreno, assumindo que o terreno é quadrado
        double lado_terreno = sqrt(area_terreno);
        
        // Exibe os dados fornecidos e o tamanho mínimo do terreno necessário
        printf("Dados: Comprimento: %.2lf, Largura: %.2lf, Percentual: %.2lf%%\n", comprimento, largura, percentual);
        printf("Tamanho mínimo do terreno necessário é: %.2lf metros\n\n", lado_terreno);
    }
    
    return 0;
}
