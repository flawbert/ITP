#include <stdio.h>
#include <string.h>

const char S[] =
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
     'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

int cValida(const char *chave) {
    if (strlen(chave) != 4) {
        printf("Chave invalida!\n");
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (chave[i] < '0' || chave[i] > '9') {
            printf("Chave invalida!\n");
            return 0;
        }
    }
    return 1;
}

int mValida(const char *mensagem) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        int caractereValido = 0;
        for (int j = 0; j < sizeof(S) / sizeof(S[0]); j++) {
            if (mensagem[i] == S[j]) {
                caractereValido = 1;
                break;
            }
        }
        if (!caractereValido) {
            printf("Caractere invalido na entrada!\n");
            return 0;
        }
    }
    return 1;
}

void cifra(char *mensagem, const char *chave) {
    int tamanhoChave = strlen(chave);
    int tamanhoMensagem = strlen(mensagem);

    for (int i = 0; i < tamanhoMensagem; i++) {
        int indiceCaractere = -1;
        for (int j = 0; j < sizeof(S) / sizeof(S[0]); j++) {
            if (mensagem[i] == S[j]) {
                indiceCaractere = j;
                break;
            }
        }
        if (indiceCaractere != -1) {
            int digitoChave = chave[i % tamanhoChave] - '0';
            int novoIndice = (indiceCaractere + digitoChave) % (sizeof(S) / sizeof(S[0]));
            mensagem[i] = S[novoIndice];
        }
    }
}

int main() {
    char chave[5];
    char mensagem[201];
    scanf("%s", chave);

    if (!cValida(chave)) {
        return 1;
    }
    scanf(" %[^\n]", mensagem);

    if (!mValida(mensagem)) {
        return 1;
    }

    cifra(mensagem, chave);
    printf("%s\n", mensagem);

    return 0;
}