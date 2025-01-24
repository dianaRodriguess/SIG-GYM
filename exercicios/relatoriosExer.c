#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelExer.h"
#include "../libs/utils.h"


void ativosExercicios() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                      Exercícios ativos                                                 |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-6s  | %-50s| %-30s  \n", "ID", "Nome", "Função");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("exercicios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de exercícios\n");
        return;
    }

    Exercicio exercicio;
    while (fread(&exercicio, sizeof(Exercicio), 1, arquivo)) {
        if (exercicio.status == 1) {
            printf("| %6d  | %-50s| %-30s \n",
                   exercicio.id_exercicio,
                   exercicio.nome,
                   exercicio.categoria);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void inativosExercicios() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                      Exercícios inativos                                               |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-6s  | %-50s| %-30s  \n", "ID", "Nome", "Função");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("exercicios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de exercícios\n");
        return;
    }

    Exercicio exercicio;
    while (fread(&exercicio, sizeof(Exercicio), 1, arquivo)) {
        if (exercicio.status == 0) {
            printf("| %6d  | %-50s| %-30s \n",
                   exercicio.id_exercicio,
                   exercicio.nome,
                   exercicio.categoria);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void allExercicios() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                      Todos os exercícios                                               |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-6s  | %-50s| %-30s  \n", "ID", "Nome", "Função");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("exercicios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de exercícios\n");
        return;
    }

    Exercicio exercicio;
    while (fread(&exercicio, sizeof(Exercicio), 1, arquivo)) {
            printf("| %6d  | %-50s| %-30s \n",
                   exercicio.id_exercicio,
                   exercicio.nome,
                   exercicio.categoria);
        
    }

    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void allExerciciosOrdenados(void) {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                             Exercicios (Ordenados por Nome)                                            |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-6s  | %-50s| %-30s  \n", "ID", "Nome", "Função");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("exercicios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    // Cria a lista encadeada
    ExercicioNo* lista = NULL;
    Exercicio exercicio;

    while (fread(&exercicio, sizeof(Exercicio), 1, arquivo)) {
        ExercicioNo* novo = (ExercicioNo*)malloc(sizeof(ExercicioNo));
        if (novo == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
            return;
        }
        novo->exercicio = exercicio; // Copia o exercício para o novo nó
        novo->proximo = lista;
        lista = novo;
    }
    fclose(arquivo);

    // Ordena a lista encadeada por nome
    if (lista != NULL) {
        ExercicioNo* i;
        ExercicioNo* j;
        for (i = lista; i->proximo != NULL; i = i->proximo) {
            for (j = i->proximo; j != NULL; j = j->proximo) {
                if (strcmp(i->exercicio.nome, j->exercicio.nome) > 0) {
                    Exercicio temp = i->exercicio;
                    i->exercicio = j->exercicio;
                    j->exercicio = temp;
                }
            }
        }
    }

    // Exibe os exercícios
    ExercicioNo* atual = lista;
    while (atual != NULL) {
        printf("| %6d  | %-50s| %-30s \n",
               atual->exercicio.id_exercicio,
               atual->exercicio.nome,
               atual->exercicio.categoria);
        atual = atual->proximo; // Avança para o próximo nó
    }

    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    // Libera a memória
    atual = lista;
    while (atual != NULL) {
        ExercicioNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
