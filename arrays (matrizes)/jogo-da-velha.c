#include <stdio.h>
#include <string.h>

int vitoria(char tabuleiro[3][3], char simb){
    for(int i = 0; i < 3; i++){
        if(tabuleiro[i][0] == simb && tabuleiro[i][1] == simb && tabuleiro[i][2] == simb){
            return 1;
        }
        if(tabuleiro[0][i] == simb && tabuleiro[1][i] == simb && tabuleiro[2][i] == simb){
            return 1;
        }
    }
    if(tabuleiro[0][0] == simb && tabuleiro[1][1] == simb && tabuleiro[2][2] == simb){
        return 1;
    }
    if(tabuleiro[0][2] == simb && tabuleiro[1][1] == simb && tabuleiro[2][0] == simb){
        return 1;
    }
    return 0;
}

int main(){
    char tabuleiro[3][3];
    
    int i,j;
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf(" %c", &tabuleiro[i][j]);
        }
    }
    
    //for(i=0;i<3;i++){
    //    for(j=0;j<3;j++){
    //        printf("%c", tabuleiro[i][j]); //Testando se a saída do tabuleiro pré-selecionado está correta.
    //    }
    //    printf("\n");
    //}
    
    int N;
    scanf("%d", &N); //Lendo o valor inteiro N de número de jogadas;
    
    char saida[500];
    int X;
    int Y;
    char simb;
    
    for(i = 0; i < N; i++){
       scanf("%d %d %c", &X, &Y, &simb);
       X--;
       Y--;
       
        //printf("%d %d %c\n", X, Y, simb); //Testando se está saindo os valores da jogada corretamente
       if(!(X >= 0  && X < 3 && Y >= 0 && Y < 3 && tabuleiro[X][Y] == '.')){
           strcat(saida, "Jogada inválida!\n");
       }
       else{
           tabuleiro[X][Y] = simb;
           if(vitoria(tabuleiro,simb)){
               strcat(saida, "Boa jogada, vai vencer!\n");
               tabuleiro[X][Y] = '.';
           }
           else{
               strcat(saida, "Continua o jogo.\n");
               tabuleiro[X][Y] = '.';
           }
       }
    }
    printf("%s", saida);
    return 0;
}