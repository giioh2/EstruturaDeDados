#include <stdio.h>

int conta_int_array(int array[], int size, int busca) {
    int count = 0;
    
    for(int i = 0; i < size; i++) {
        if(array[i] == busca) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int array[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int busca = 7;
    
    int resultado = conta_int_array(array, size, busca);
    
    printf("%d\n", resultado);
    
    return 0;
}
