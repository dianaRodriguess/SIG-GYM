#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "model.h"
#include "controller.h"
#include "../libs/entradas.h"
#include "../libs/utils.h"
#include "../libs/leitura_dados.h"
#include "relatorios.h"


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