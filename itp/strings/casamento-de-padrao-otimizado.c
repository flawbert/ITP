#include <stdio.h>
#include <string.h>

int main() {
    char analisa[50], busca[50];
    int i, j, t = 0;
    scanf("%s", analisa);
    scanf("%s", busca);
    char *resultado = strstr(analisa, busca);
    int lenA = strlen(analisa);
    int lenP = strlen(busca);
    
    for(i = 0; i < lenP; i++){
        if(busca[i] == 'T'){
            t = 1;
        }
    }

    for(i = 0; i < lenA; i++){
        for(j = 0; j < lenP; j++){
            if(lenA - i < lenP){
                i = lenA;
                break;
            }
            else if(analisa[i+j] == busca[j]){
                printf("%c ", analisa[i+j]);
                if(j == lenP - 1){
                    printf("sim\n");
                    i = i + j;
                }
            }
            else{
                printf("%c não\n", analisa[i+j]);
                if(analisa[i+j] == 'T' && !t){
                    i = i + j;
                }
                break;
            }
        }
    }

    if(resultado != NULL){
        printf("Achei o padrão no índice %ld\n", resultado - analisa);
    }
    else{
        printf("Não achei o padrão\n");
    }

    return 0;
}