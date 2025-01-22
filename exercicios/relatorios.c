#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
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