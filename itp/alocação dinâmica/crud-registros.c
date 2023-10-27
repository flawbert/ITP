#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    int idade;
    char sexo;
};

// Função para criar uma pessoa
struct Pessoa criar() {
    struct Pessoa pessoa;
    scanf(" %[^\n]", pessoa.nome);
    scanf("%d", &pessoa.idade);
    scanf(" %c", &pessoa.sexo);
    return pessoa;
}

// Função para inserir uma pessoa no vetor
void inserir(struct Pessoa **vetor, int *tamanho, struct Pessoa novaPessoa) {
    (*tamanho)++;
    (*vetor) = (struct Pessoa *)realloc((*vetor), (*tamanho) * sizeof(struct Pessoa));
    (*vetor)[(*tamanho) - 1] = novaPessoa;
}
//Função de deletar pessoa no vetor
void deletar(struct Pessoa **vetor, int *tamanho, struct Pessoa pessoaParaDeletar) {
    for (int i = 0; i < (*tamanho); i++) {
        if (strcmp((*vetor)[i].nome, pessoaParaDeletar.nome) == 0 &&
            (*vetor)[i].idade == pessoaParaDeletar.idade &&
            (*vetor)[i].sexo == pessoaParaDeletar.sexo) {
            for (int j = i; j < (*tamanho) - 1; j++) {
                (*vetor)[j] = (*vetor)[j + 1];
            }
            (*tamanho)--;
            (*vetor) = (struct Pessoa *)realloc((*vetor), (*tamanho) * sizeof(struct Pessoa));
            i--;
        }
    }
}

void imprimir(struct Pessoa *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s,%d,%c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
    }
}

int main() {
    struct Pessoa *pessoas = NULL;
    int tamanho = 0;
    char opcao;

    while (1) {
        scanf(" %c", &opcao);

        if (opcao == 'i') {
            struct Pessoa novaPessoa = criar();
            inserir(&pessoas, &tamanho, novaPessoa);
        } else if (opcao == 'd') {
            struct Pessoa pessoaParaDeletar = criar();
            deletar(&pessoas, &tamanho, pessoaParaDeletar);
        } else if (opcao == 'p') {
            imprimir(pessoas, tamanho);
            break;
        } else if (opcao == 's') {
            break;
        } else {
            printf("ERRO! Opção inexistente!.\n");
        }
    }

    free(pessoas);
    return 0;
}
