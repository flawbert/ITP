#include <stdio.h>

struct Celular {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
};

int cadastraCelular(int qnt_cadastrada, struct Celular celulares[]);
int pesquisaCelulares(int qnt_cadastrada, struct Celular celulares[], struct Celular reqMin);

int main() {
    int qnt_cadastrada = 0;
    struct Celular celulares[100];
    char resposta;

    // Cadastro de celulares
    do {
        scanf(" %c", &resposta);
        
        if (resposta == 's') {
            qnt_cadastrada = cadastraCelular(qnt_cadastrada, celulares);
        }
    } while (resposta == 's');

    struct Celular reqMin;
    
    scanf("%d", &reqMin.memoria);
    scanf("%f", &reqMin.processador);
    scanf("%f", &reqMin.camera);
    scanf("%f", &reqMin.bateria);

    // Pesquisa celulares compatíveis
    int encontrados = pesquisaCelulares(qnt_cadastrada, celulares, reqMin);

    if (encontrados > 0) {
        printf("%d smartphones encontrados.\n", encontrados);
    } else {
        printf("%d smartphones encontrados.\n", encontrados);
    }

    return 0;
}

// Função para cadastrar um celular e retornar a quantidade de celulares cadastrados
int cadastraCelular(int qnt_cadastrada, struct Celular celulares[]) {
    scanf(" %[^\n]s", celulares[qnt_cadastrada].modelo);
    scanf("%d", &celulares[qnt_cadastrada].memoria);
    scanf("%f", &celulares[qnt_cadastrada].processador);
    scanf("%f", &celulares[qnt_cadastrada].camera);
    scanf("%f", &celulares[qnt_cadastrada].bateria);
    qnt_cadastrada++;
    return qnt_cadastrada;
}

// Função para pesquisar celulares compatíveis com os requisitos mínimos
int pesquisaCelulares(int qnt_cadastrada, struct Celular celulares[], struct Celular reqMin) {
    int encontrados = 0;

    for (int i = 0; i < qnt_cadastrada; i++) {
        if (celulares[i].memoria >= reqMin.memoria &&
            celulares[i].processador >= reqMin.processador &&
            celulares[i].camera >= reqMin.camera &&
            celulares[i].bateria >= reqMin.bateria) {
            encontrados++;
            printf("Modelo: %s\n", celulares[i].modelo);
            printf("Memoria: %dGB\n", celulares[i].memoria);
            printf("Processador: %.2fGhz\n", celulares[i].processador);
            printf("Camera: %.2fMPixels\n", celulares[i].camera);
            printf("Bateria: %.2fmA\n", celulares[i].bateria);
            
            printf("\n");
        }
    }
    
    return encontrados;
}