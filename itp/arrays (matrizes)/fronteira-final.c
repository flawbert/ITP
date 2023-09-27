#include <stdio.h>

int main(){
    int n,m;
    
    scanf("%d %d", &n, &m); //Lendo a quantidade de linhas e colunas da matriz.
    
	char planeta[n][m];
	
	char til = '~';
	char xis = 'X';
	char acento = '^';
	char asterisco = '*';
	char ponto = '.';
    
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    int c5 = 0;
    
		
	int i, j;

	for(i=0; i<n;i++){
		for(j=0;j<m;j++){
		    scanf(" %c", &planeta[i][j]);
		    if (planeta[i][j] == til){
		        c1++;
		    }
		    else if(planeta[i][j] == xis){
		        c2++;
		    }
		    else if(planeta[i][j] == acento){
		        c3++;
		    }
		    else if(planeta[i][j] == asterisco){
		        c4++;
		    }
		    else{
		        c5++;
		    }
		}
	}
	
	//for(i=0; i<n; i++){                 //Teste de impressão da matriz, não necessário para utilizar no código final.
	  //  for(j=0;j<n;j++){
	    //    printf("%c ",planeta[i][j]);
	   // }
	   // printf("\n");
//	}
    if((double)c1 / (n*m) >= 0.5 && (double)c4 / (n*m) >= 0.2 && (double)c2 == 0){
        printf("Planeta Classe M");
    }
    else if((double)c2 >= 1){
        printf("Planeta Hostil");
    }
    else if((double)c1 / (n*m) >= 0.85){
        printf("Planeta Aquático");
    }
    else if((double)c3 / (n*m) >= 0.6){
        printf("Planeta Desértico");
    }
    else if((double)c4 / (n*m) >= 0.65){
        printf("Planeta Selvagem");
    }
    else{
        printf("Planeta Inóspito");
    }
	
	return 0;
}