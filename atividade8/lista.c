#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criarLista() {
    No* cabeca = (No*)malloc(sizeof(No));
    if (cabeca != NULL) {
        cabeca->proximo = NULL;
    }
    return cabeca;
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->valor = valor;
        No* anterior = L;
        for (int j = 0; j < i; j++) {
            if (anterior->proximo == NULL) {
                free(novoNo);
                return;
            }
            anterior = anterior->proximo;
        }
        novoNo->proximo = anterior->proximo;
        anterior->proximo = novoNo;
    }
}

void lista_remover_no_i(No* L, int i) {
    No* anterior = L;
    for (int j = 0; j < i; j++) {
        if (anterior->proximo == NULL) {
            return;
        }
        anterior = anterior->proximo;
    }
    if (anterior->proximo != NULL) {
        No* temp = anterior->proximo;
        anterior->proximo = temp->proximo;
        free(temp);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* anterior = L;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            anterior->proximo = atual->proximo;
            free(atual);
            atual = anterior->proximo;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void liberarLista(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(L);
}