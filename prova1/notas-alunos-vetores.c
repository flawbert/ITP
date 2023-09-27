#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    
    float notas[n];
    
    int aA[n];
    int aRec[n];
    int aRep[n];
    
    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;
    
    for(int i = 0; i < n; i++){
        int num;
        float nota;
        scanf("%d - %f", &num, &nota);
        notas[i] = nota;
        
        if(nota >= 7.0){
            aA[aprovados++] = num;
        }
        else if(nota >= 5.0 && nota < 7.0){
            aRec[recuperacao++] = num;
        }
        else{
            aRep[reprovados++] = num;
        }
    }
    printf("Aprovados: ");
    for(int j = 0; j < aprovados; j++){
        printf("%d (%.1f)", aA[j], notas[aA[j] - 1]);
        if(j < aprovados - 1){
            printf(", ");
        }
    }
    printf("\n");
    
    printf("Recuperação: ");
    for(int j = 0; j < recuperacao; j++){
        printf("%d (%.1f)", aRec[j], notas[aRec[j] - 1]);
        if(j < recuperacao - 1){
            printf(", ");
        }
    }
    printf("\n");
    
    printf("Reprovados: ");
    for(int j = 0; j < reprovados; j++){
        printf("%d (%.1f)", aRep[j], notas[aRep[j] - 1]);
        if(j < reprovados - 1){
            printf(", ");
        }
    }
    printf("\n");
    
    return 0;
}