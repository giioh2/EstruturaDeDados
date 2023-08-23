#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

void calcularRegressaoLinear(Ponto* dados, int quantidade) {
    double somaX = 0;
    double somaY = 0;
    
    for (int i = 0; i < quantidade; i++) {
        somaX += dados[i].x;
        somaY += dados[i].y;
    }
    
    double mediaX = somaX / quantidade;
    double mediaY = somaY / quantidade;
    
    double somaXY = 0;
    double somaXX = 0;
    
    for (int i = 0; i < quantidade; i++) {
        somaXY += dados[i].x * dados[i].y;
        somaXX += dados[i].x * dados[i].x;
    }
    
    double inclinacao = (somaXY - quantidade * mediaX * mediaY) / (somaXX - quantidade * mediaX * mediaX);
    double interceptacao = mediaY - inclinacao * mediaX;
    
    printf("Equação da regressão linear: y = %.2fx + %.2f\n", inclinacao, interceptacao);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }
    
    FILE* arquivo = fopen(argv[1], "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    int quantidadeRegistros = 0;
    
    // Contar a quantidade de registros no arquivo
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        quantidadeRegistros++;
    }
    
    // Alocar dinamicamente um array de struct Ponto
    Ponto* dados = malloc(quantidadeRegistros * sizeof(Ponto));
    
    if (dados == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }
    
    // Voltar para o início do arquivo
    rewind(arquivo);
    
    // Ler os pontos do arquivo
    for (int i = 0; i < quantidadeRegistros; i++) {
        double x, y;
        fscanf(arquivo, "%lf,%lf", &x, &y);
        dados[i].x = x;
        dados[i].y = y;
    }
    
    fclose(arquivo);
    
    // Calcular a regressão linear
    calcularRegressaoLinear(dados, quantidadeRegistros);
    
    free(dados);
    
    return 0;
}