#include <stdio.h>
#include <string.h>

const char S[] =  {'0','1','2','3','4','5','6','7','8','9',
                   'A','B','C','D','E','F','G','H','I','J',
                   'K','L','M','N','O','P','Q','R','S','T',
                   'U','V','W','X','Y','Z','.',',','?',' '};
     
void chaveV(char c[], int k[], char kp[], int kpl[], int x[]){
    int aux = 0, i = 0, j = 0;

    while (aux < 4 && i < strlen(kp) - 4){
        int n1 = ((kpl[i] - x[j]) + 40) % 40;
        int n2 = ((kpl[i+4] - x[j+4]) + 40) % 40;

        if (n1 == n2){
            k[i % 4] = n1;
            aux++, i++, j++;
        } else i -= aux, aux = 0, j = 0, i++;
    }

    if(!aux){
        printf("Mensagem nao e da Resistencia!\n");
        kp[0] = '\0';
    } else{
        for(int i = 0; i < 4; i++){
            printf("%i", k[i]);
        }
        printf("\n");
    }
}

void decifra(char c[], int k[]){
    for (int i = 0; i < strlen(c); i++){
        for (int j = 0; j < 40; j++){
             if (c[i] == S[j]) {
                c[i] = S[((j-k[i % 4]) + 40) % 40];
                break;
            }
        }
    }
}

int main(){
    char frag[] = "QUE A FORCA ESTEJA COM VOCE";
    int frag_pos[27] = {0};
    
    for (int i = 0; i < strlen(frag); i++)
        for (int j = 0; j < sizeof(S); j++)
            if (frag[i] == S[j])
                frag_pos[i] = j;

    char mensagemc[202];
    fgets(mensagemc, sizeof(mensagemc), stdin);
    if (mensagemc[strlen(mensagemc)-1] == '\n')
        mensagemc[strlen(mensagemc)-1] = '\0';

    int mensagemc_pos[200] = {0};
    
    for (int i = 0; i < strlen(mensagemc); i++)
        for (int j = 0; j < sizeof(S); j++)
            if (mensagemc[i] == S[j])
                mensagemc_pos[i] = j;

    int chave[4] = {0};
    chaveV(frag, chave, mensagemc, mensagemc_pos, frag_pos);
    decifra(mensagemc, chave);

    printf("%s", mensagemc);
    
    return 0;
}