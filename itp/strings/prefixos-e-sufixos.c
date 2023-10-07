#include <stdio.h>
#include <string.h>

void removeSufixo(char *palavra, const char *sufixo) {
    int palavraLen = strlen(palavra);
    int sufixoLen = strlen(sufixo);

    if (palavraLen < sufixoLen) {
        return;
    }

    int i = palavraLen - 1;
    int j = sufixoLen - 1;

    while (j >= 0 && palavra[i] == sufixo[j]) {
        i--;
        j--;
    }

    if (j < 0) {
        palavra[i + 1] = '\0'; 
    }
}

void removePrefixo(char *palavra, const char *prefixo) {
    int palavraLen = strlen(palavra);
    int prefixoLen = strlen(prefixo);

    if (palavraLen < prefixoLen) {
        return;
    }

    int i = 0;
    int j = 0;

    while (j < prefixoLen && palavra[i] == prefixo[j]) {
        i++;
        j++;
    }

    if (j == prefixoLen) {
        strcpy(palavra, palavra + i);
    }
}

int main() {
    int numPrefixos, numSufixos;
    char prefixos[100][11];
    char sufixos[100][11];
    char palavra[101];

    scanf("%d", &numPrefixos);
    for (int i = 0; i < numPrefixos; i++) {
        scanf("%s", prefixos[i]);
    }

    scanf("%d", &numSufixos);
    for (int i = 0; i < numSufixos; i++) {
        scanf("%s", sufixos[i]);
    }

    while (scanf("%s", palavra) != EOF && strcmp(palavra, "-1") != 0) {
        int removeu = 0;

        for (int i = 0; i < numSufixos; i++) {
            removeSufixo(palavra, sufixos[i]);
            if (strlen(palavra) == 0) {
                removeu = 1;
                break;
            }
        }

        if (!removeu) {
            for (int i = 0; i < numPrefixos; i++) {
                removePrefixo(palavra, prefixos[i]);
                if (strlen(palavra) == 0) {
                    break;
                }
            }
            
        if (strlen(palavra) > 0) {
            printf("%s\n", palavra);
        }
    }

    }
    
    return 0;
}