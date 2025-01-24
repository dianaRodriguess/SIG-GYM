#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewFun.h"
#include "modelFun.h"
#include "controllerFun.h"
#include "../libs/entradas.h"
#include "../libs/utils.h"
#include "../libs/leitura_dados.h"
#include "relatoriosFun.h"


void ativosDadosFuncionarios() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Funcionários ativos                                                             |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10s  |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.status == 1) {
            printf("| %-50s| %-14s  | %-12s |%-20s| %-13s    | %-10d  |\n",
                   funcionario.nome,
                   funcionario.cpf,
                   funcionario.telefone,
                   funcionario.email,
                   funcionario.dataNasc,
                   funcionario.cargo);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void inativosDadosFuncionarios() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Funcionários inativos                                                           |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10s  |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.status == 0) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10d  |\n",
                   funcionario.nome,
                   funcionario.cpf,
                   funcionario.telefone,
                   funcionario.email,
                   funcionario.dataNasc,
                   funcionario.cargo);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void allFuncionarios() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Todos os usuários                                                               |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s | %-13s    | %-10s  | %-5s  |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo", "Status");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        
        printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10d  |  %-5d  \n",
                funcionario.nome,
                funcionario.cpf,
                funcionario.telefone,
                funcionario.email,
                funcionario.dataNasc,
                funcionario.cargo,
                funcionario.status);
        
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void dadosFuncionariosGerente() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                           Gerentes                                                                   |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10s  |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.cargo == Gerente) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10d  |\n",
                   funcionario.nome,
                   funcionario.cpf,
                   funcionario.telefone,
                   funcionario.email,
                   funcionario.dataNasc,
                   funcionario.cargo);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}


void dadosFuncionariosProfessor() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                         Professores                                                                  |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10s  |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.cargo == Professor) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10d  |\n",
                   funcionario.nome,
                   funcionario.cpf,
                   funcionario.telefone,
                   funcionario.email,
                   funcionario.dataNasc,
                   funcionario.cargo);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void dadosFuncionariosASG() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                        ASG's                                                                         |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10s  |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.cargo == ASG) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10d  |\n",
                   funcionario.nome,
                   funcionario.cpf,
                   funcionario.telefone,
                   funcionario.email,
                   funcionario.dataNasc,
                   funcionario.cargo);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void dadosFuncionariosAtendente() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Atendentes                                                                      |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10s  |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.cargo == Atendente) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-10d  |\n",
                   funcionario.nome,
                   funcionario.cpf,
                   funcionario.telefone,
                   funcionario.email,
                   funcionario.dataNasc,
                   funcionario.cargo);
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void allFuncionariosOrdenados(void) {
    limparTela();
    printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                  Funcionários (Ordenados por Nome)                                                     |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-27s| %-16s    | %-5s          |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc.", "Cargo");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    // Cria a lista encadeada
    FuncionarioNo* lista = NULL;
    Funcionario funcionario;

    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        FuncionarioNo* novo = (FuncionarioNo*)malloc(sizeof(FuncionarioNo));
        if (novo == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
            return;
        }
        novo->funcionario = funcionario; // Copia o exercício para o novo nó
        novo->proximo = lista;
        lista = novo;
    }
    fclose(arquivo);

    // Ordena a lista encadeada por nome
    if (lista != NULL) {
        FuncionarioNo* i;
        FuncionarioNo* j;
        for (i = lista; i->proximo != NULL; i = i->proximo) {
            for (j = i->proximo; j != NULL; j = j->proximo) {
                if (strcmp(i->funcionario.nome, j->funcionario.nome) > 0) {
                    Funcionario temp = i->funcionario;
                    i->funcionario = j->funcionario;
                    j->funcionario = temp;
                }
            }
        }
    }

    // Exibe os exercícios
    FuncionarioNo* atual = lista;
    while (atual != NULL) {
        
        printf("| %-50s| %-14s  | %-12s | %-27s| %-16s    | %-5d          |\n",
            atual->funcionario.nome,
            atual->funcionario.cpf,
            atual->funcionario.telefone,
            atual->funcionario.email,
            atual->funcionario.dataNasc,
            atual->funcionario.cargo);
        atual = atual->proximo; 
    }

    printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    
    atual = lista;
    while (atual != NULL) {
        FuncionarioNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
