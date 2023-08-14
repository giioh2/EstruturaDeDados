#include <stdio.h>

void multiplica_array(int array1[], int array2[], int size, int resultado[]) {
    for(int i = 0; i < size; i++) {
        resultado[i] = array1[i] * array2[i];
    }
}

int main() {
    int array1[] = {5, 7, 9, 6};
    int array2[] = {5, 7, 9, 6};
    int size = sizeof(array1) / sizeof(array1[0]);
    int resultado[size];
    
    multiplica_array(array1, array2, size, resultado);
    
    for(int i = 0; i < size; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");
    
    return 0;
}
