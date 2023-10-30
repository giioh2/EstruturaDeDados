#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

char* tabela_hash[TABLE_SIZE];


int hash(char* chave) {
    int valor = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        valor += chave[i];
    }
    return valor % TABLE_SIZE;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    tabela_hash[index] = dado;
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    return tabela_hash[index];
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    return tabela_hash[index] != NULL;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    tabela_hash[index] = NULL;
}