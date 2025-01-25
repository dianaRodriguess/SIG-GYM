#include <stdio.h>
#include <string.h>
#include "modelCli.h"
#include <stdlib.h>
#include "../libs/utils.h"

void listarClientesAtivos(void){
    limparTela();
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                            Clientes ativos                                                                         |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-26s| %-13s    | %-10s      | %-10s   |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.status == Ativo) {
            printf("| %-50s| %-14s  | %-12s | %-26s| %-16s | %-10s      | %-13s |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   nomeSexo(cliente.sexo),
                   nomePlano(cliente.plano));
        }
    }
    
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    fclose(arquivo);
}

void listarClientesInativos(void){
    limparTela();
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                             Clientes inativos                                                                      |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-26s| %-13s    | %-10s      | %-10s   |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.status == Inativo) {
            printf("| %-50s| %-14s  | %-12s | %-26s| %-16s | %-10s      | %-13s |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   nomeSexo(cliente.sexo),
                   nomePlano(cliente.plano));
        }
    }
    
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
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
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                           Clientes básicos                                                                         |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-26s| %-13s    | %-10s      | %-10s   |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.plano == Basico) {
            printf("| %-50s| %-14s  | %-12s | %-26s| %-16s | %-10s      | %-13s |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   nomeSexo(cliente.sexo),
                   nomePlano(cliente.plano));
        }
    }
    
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    fclose(arquivo);
}

void listarClientesIntermediario(void){
    limparTela();
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                       Clientes intermediários                                                                      |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-26s| %-13s    | %-10s      | %-10s   |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.plano == Intermediario) {
            printf("| %-50s| %-14s  | %-12s | %-26s| %-16s | %-10s      | %-13s |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   nomeSexo(cliente.sexo),
                   nomePlano(cliente.plano));
        }
    }
    
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    fclose(arquivo);
}

void listarClientesAvancado(void){
    limparTela();
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                         Clientes avançados                                                                         |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-26s| %-13s    | %-10s      | %-10s   |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
        if(arquivo == NULL){
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
        }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)){
        if (cliente.plano == Avancado) {
            printf("| %-50s| %-14s  | %-12s | %-26s| %-16s | %-10s      | %-13s |\n",
                    cliente.nome,
                   cliente.cpf,
                   cliente.telefone,
                   cliente.email,
                   cliente.dataNasc,
                   nomeSexo(cliente.sexo),
                   nomePlano(cliente.plano));
        }
    }
    
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    fclose(arquivo);
}

void allClientesOrdenado() {
    limparTela();
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                          Clientes (Ordenados por Nome)                                                             |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-26s| %-13s    | %-10s      | %-10s   |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Sexo", "Plano");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    ClienteNo* lista = NULL;
    Cliente cliente;

    // Lê os clientes do arquivo e monta a lista encadeada
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) {
        ClienteNo* novo = (ClienteNo*)malloc(sizeof(ClienteNo));
        if (novo == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
            return;
        }
        novo->cliente = cliente;
        novo->proximo = lista;
        lista = novo;
    }
    fclose(arquivo);

    
    if (lista != NULL) {
        ClienteNo* i;
        ClienteNo* j;
        for (i = lista; i->proximo != NULL; i = i->proximo) {
            for (j = i->proximo; j != NULL; j = j->proximo) {
                if (strcmp(i->cliente.nome, j->cliente.nome) > 0) {
                    
                    Cliente temp = i->cliente;
                    i->cliente = j->cliente;
                    j->cliente = temp;
                }
            }
        }
    }

    // Exibe os clientes na ordem ordenada
    ClienteNo* atual = lista;
    while (atual != NULL) {
        printf("| %-50s| %-14s  | %-12s | %-26s| %-16s | %-10s      | %-13s |\n",
               atual->cliente.nome,
               atual->cliente.cpf,
               atual->cliente.telefone,
               atual->cliente.email,
               atual->cliente.dataNasc,
               nomeSexo(atual->cliente.sexo),
               nomePlano(atual->cliente.plano));
        atual = atual->proximo;
    }

    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    // Libera a memória
    atual = lista;
    while (atual != NULL) {
        ClienteNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}