#include <stdio.h>

int main() {
    int largura;

    scanf("%d", &largura);

    int piramide[largura][largura];

    for (int i = 0; i < largura; i++) {
        for (int j = i; j < largura - i; j++) {
            piramide[i][j] = i + 1;
            piramide[j][i] = i + 1;
            piramide[largura - i - 1][j] = i + 1;
            piramide[j][largura - i - 1] = i + 1;
        }
    }
    
    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < largura; j++) {
            printf("%d", piramide[i][j]);
            if (j < largura - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}