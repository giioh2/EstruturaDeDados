#include "fila.h"
#include <stdlib.h>

Fila* criar_fila(int tamanho_maximo) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->tamanho_maximo = tamanho_maximo;
    fila->inicio = 0;
    fila->fim = -1;
    fila->contador = 0;
    fila->dados = (int*)malloc(sizeof(int) * tamanho_maximo);
    return fila;
}

int esta_vazia(Fila* fila) {
    return (fila->contador == 0);
}

int esta_cheia(Fila* fila) {
    return (fila->contador == fila->tamanho_maximo);
}

void enfileirar(Fila* fila, int elemento) {
    if (esta_cheia(fila)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    fila->fim = (fila->fim + 1) % fila->tamanho_maximo;
    fila->dados[fila->fim] = elemento;
    fila->contador++;
}

int desenfileirar(Fila* fila) {
    if (esta_vazia(fila)) {
        printf("Erro: Fila vazia!\n");
        return -1; 
    }
    int elemento = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->tamanho_maximo;
    fila->contador--;
    return elemento;
}

void liberar_fila(Fila* fila) {
    free(fila->dados);
    free(fila);
}