#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTICIPANTES 100

int main() {
    char PARTICIPANTES[MAX_PARTICIPANTES][100];
    int N = 0;
    int sorteado[MAX_PARTICIPANTES] = {0};
    int i;
    char nome[100];
    while (1) {
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        
        if (strcmp(nome, "acabou") == 0) {
            break;
        }
        
        if (N < MAX_PARTICIPANTES) {
            strcpy(PARTICIPANTES[N], nome);
            N++;
        } else {
            printf("Máx. atingido!.\n");
            break;
        }
    }
    int semente;
    scanf("%d", &semente);
    srand((unsigned)semente);
    
    for (i = 0; i < N; i++) {
        int indice_participante;
        do {
            indice_participante = rand() % N;
        } while (sorteado[indice_participante]);
        
        sorteado[indice_participante] = 1;
        printf("%s\n", PARTICIPANTES[indice_participante]);
    }
    
    return 0;
}