#ifndef FILA_H
#define FILA_H

typedef struct {
    int tamanho_maximo;
    int inicio;
    int fim;
    int contador;
    int* dados;
} Fila;

Fila* criar_fila(int tamanho_maximo);
int esta_vazia(Fila* fila);
int esta_cheia(Fila* fila);
void enfileirar(Fila* fila, int elemento);
int desenfileirar(Fila* fila);
void liberar_fila(Fila* fila);

#endif