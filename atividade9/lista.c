#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct No {
    float valor;
    struct No* proximo;
} No;

void lista_inserir_no_ordenado(No** L, float valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (*L == NULL || valor < (*L)->valor) {
        novo_no->proximo = *L;
        *L = novo_no;
    } else {
        No* atual = *L;
        while (atual->proximo != NULL && atual->proximo->valor <= valor) {
            atual = atual->proximo;
        }
        novo_no->proximo = atual->proximo;
        atual->proximo = novo_no;
    }
}

int main() {
    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    // Leitura do arquivo
    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[20];
    float numero;
    clock_t inicio, fim;
    double tempo_nao_ordenado = 0.0;
    double tempo_ordenado = 0.0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numero = atof(linha);

        inicio = clock();
        lista_inserir_no_ordenado(&lista_nao_ordenada, numero);
        fim = clock();
        tempo_nao_ordenado += (double)(fim - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        lista_inserir_no_ordenado(&lista_ordenada, numero);
        fim = clock();
        tempo_ordenado += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    fclose(arquivo);


    int numero_de_elementos = 1000000;  
    double media_nao_ordenado = tempo_nao_ordenado / numero_de_elementos;
    double media_ordenado = tempo_ordenado / numero_de_elementos;

    printf("Tempo médio de inserção em lista não ordenada: %lf segundos\n", media_nao_ordenado);
    printf("Tempo médio de inserção em lista ordenada: %lf segundos\n", media_ordenado);

   
    while (lista_nao_ordenada != NULL) {
        No* temp = lista_nao_ordenada;
        lista_nao_ordenada = lista_nao_ordenada->proximo;
        free(temp);
    }

    while (lista_ordenada != NULL) {
        No* temp = lista_ordenada;
        lista_ordenada = lista_ordenada->proximo;
        free(temp);
    }

    return 0;
}