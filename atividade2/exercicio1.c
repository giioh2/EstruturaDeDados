#include <stdio.h>
#include <stdlib.h>

int soma_array(int arr[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return soma;
}


int main() {
    int arr[] = {5, 7, 9, 6};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int soma = soma_array(arr, tamanho);
    printf("Soma: %d\n", soma);
    return 0;


    return (0);
}
