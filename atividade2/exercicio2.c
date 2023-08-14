#include <stdio.h>

void menor_maior_array(int array[], int size, int *menor, int *maior) {
    *menor = array[0];
    *maior = array[0];
    
    for(int i = 1; i < size; i++) {
        if(array[i] < *menor) {
            *menor = array[i];
        }
        if(array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
    int array[] = {5, 7, 9, 6};
    int size = sizeof(array) / sizeof(array[0]);
    int menor, maior;
    
    menor_maior_array(array, size, &menor, &maior);
    
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);
    
    return 0;
}
