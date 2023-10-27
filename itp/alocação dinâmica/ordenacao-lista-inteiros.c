#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int *numeros = NULL;
    int tamanho = 0;
    int numero;
    while (scanf("%d", &numero) != EOF) {
        tamanho++;
        numeros = (int *)realloc(numeros, tamanho * sizeof(int));
        if (numeros == NULL) {
            printf("Erro!\n");
            return 1;
        }
        numeros[tamanho - 1] = numero;
    }
    qsort(numeros, tamanho, sizeof(int), comparar);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    free(numeros);

    return 0;
}
