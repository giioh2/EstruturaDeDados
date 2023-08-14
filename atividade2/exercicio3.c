#include <stdio.h>

int busca_string(char *array[], int size, char *busca) {
    for(int i = 0; i < size; i++) {
        if(strcmp(array[i], busca) == 0) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char *array[] = {"texto", "J", "EDA"};
    int size = sizeof(array) / sizeof(array[0]);
    char *busca = "EDO";
    
    int resultado = busca_string(array, size, busca);
    
    printf("%d\n", resultado);
    
    return 0;
}
