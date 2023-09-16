#include <stdio.h>

void diferencaSimetrica(int N, int M, int cA[50], int cB[50], int num){
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        cA[num] = 1;
    }
    
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        cB[num] = 1;
    }
    
}
int main(){
    int N;
    int M;
    
    scanf("%d %d", &N, &M);
    
    int cA[50] = {0};
    int cB[50] = {0};
    
    int num;
    
    diferencaSimetrica(N, M, cA, cB, num);
    
    for (int i = 0; i < 50; i++) {
        if ((cA[i] || cB[i]) && !(cA[i] && cB[i])) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    return 0;
    
}