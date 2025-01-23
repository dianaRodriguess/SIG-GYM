#include <stdio.h>
#include <string.h>
#include "modelCli.h"
#include "../libs/utils.h"


void listarClientesAtivos(void){

    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Clientes ativos                                                                 |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-1s      | %-6s     |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.status == Ativo) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-16s | %-4c      | %-10d |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   cliente.sexo == Masculino ? 'M' : 'F', 
                   cliente.plano);
        }
    }
    
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void listarClientesInativos(void){

    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Clientes inativos                                                               |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-1s      | %-6s     |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.status == Inativo) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-16s | %-4c      | %-10d |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   cliente.sexo == Masculino ? 'M' : 'F', 
                   cliente.plano);
        }
    }
    
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void allClientes(void){

    limparTela();
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Todos os clientes                                                                        |\n");
    printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|%-50s | %-14s  | %-12s | %-20s | %-13s    | %-10s  | %-5s  |  %-5s |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano", "Status");
    printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
    
        printf("| %-50s| %-14s  | %-12s | %-20s| %-16s | %-4c      | %-10d | %-5d\n",
                cliente.nome,
                cliente.cpf,
                cliente.telefone,
                cliente.email,
                cliente.dataNasc,
                cliente.sexo == Masculino ? 'M' : 'F', 
                cliente.plano, cliente.status);
    }
    
    
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void listarClientesBasico(void){

    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Clientes básicos                                                                |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  %-50s| %-14s  | %-12s | %-20s| %-13s    | %-1s      | %-6s     |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.plano == Basico) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-16s | %-4c      | %-10d |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   cliente.sexo == Masculino ? 'M' : 'F', 
                   cliente.plano);
        }
    }
    
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void listarClientesIntermediario(void){

    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                   Clientes intermediários                                                            |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-1s      | %-6s     |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.plano == Intermediario) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-16s | %-4c      | %-10d |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   cliente.sexo == Masculino ? 'M' : 'F', 
                   cliente.plano);
        }
    }
    
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}

void listarClientesAvancado(void){

    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Clientes avançados                                                              |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-1s      | %-6s     |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.plano == Avancado) {
            printf("| %-50s| %-14s  | %-12s | %-20s| %-16s | %-4c      | %-10d |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   cliente.sexo == Masculino ? 'M' : 'F', 
                   cliente.plano);
        }
    }
    
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    fclose(arquivo);
}