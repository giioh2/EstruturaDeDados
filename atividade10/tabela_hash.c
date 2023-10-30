#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    
    printf("Valor para chave1: %s\n", hash_table_get("chave1"));
    printf("Valor para chave2: %s\n", hash_table_get("chave2"));
    
    if (hash_table_contains("chave3")) {
        printf("A chave3 está na tabela.\n");
    } else {
        printf("A chave3 não está na tabela.\n");
    }
    
    hash_table_remove("chave2");
    
    if (hash_table_contains("chave2")) {
        printf("A chave2 está na tabela.\n");
    } else {
        printf("A chave2 não está na tabela.\n");
    }
    
    return 0;
}