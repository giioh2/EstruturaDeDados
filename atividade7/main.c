#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {
 
    Pilha* pilha = criar_pilha(5);

    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);

    printf("Elemento desempilhado: %d\n", desempilhar(pilha)); // 30
    printf("Elemento desempilhado: %d\n", desempilhar(pilha)); // 20

    liberar_pilha(pilha);


    Fila* fila = criar_fila(5);

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    printf("Elemento desenfileirado: %d\n", desenfileirar(fila)); // 10
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila)); // 20

    liberar_fila(fila);

    return 0;
}