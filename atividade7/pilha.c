#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int tamanho_maximo;
    int topo;
    int* dados;
} Pilha;

Pilha* criar_pilha(int tamanho_maximo);
int esta_vazia(Pilha* pilha);
int esta_cheia(Pilha* pilha);
void empilhar(Pilha* pilha, int elemento);
int desempilhar(Pilha* pilha);
void liberar_pilha(Pilha* pilha);

#endif