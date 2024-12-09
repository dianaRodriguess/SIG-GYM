#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/utils.h"
#include "model.h"
#include "../libs/leitura_dados.h"

void salvarCliente(Cliente* cliente){
    FILE* arquivo = fopen("clientes.dat", "ab");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    fwrite(cliente, sizeof(Cliente), 1, arquivo);
    fclose(arquivo);
    free(cliente);
}

Cliente* carregarClientes(char* cpf){
    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente));
    FILE* arquivo = fopen("clientes.dat", "rb");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    while (fread(cliente, sizeof(Cliente), 1, arquivo)) {
    if ((!strcmp(cliente->cpf, cpf)) && (cliente->status == 1)) {
        fclose(arquivo);
        return cliente;
    }}

    fclose(arquivo);
    free(cliente);
    return NULL;
}

int regravaCliente(Cliente* cliente){
    FILE* arquivo = fopen("clientes.dat", "r+b");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    while (fread(novoCliente, sizeof(Cliente), 1, arquivo)) {
        if (!strcmp(novoCliente->cpf, cliente->cpf)) {
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, arquivo);
            fclose(arquivo);
            free(novoCliente);
            free(cliente);
            return 1;
        }
    }

    fclose(arquivo);
    free(novoCliente);
    free(cliente);
    return -1;
}

int excluirCliente(Cliente* cliente, char* cpf){
    FILE* arquivo = fopen("clientes.dat", "r+b");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    while(fread(cliente, sizeof(Cliente), 1, arquivo)){
        if(!strcmp(cliente->cpf, cpf) && cliente->status == 1){
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            cliente->status = 0;
            fwrite(cliente, sizeof(Cliente), 1, arquivo);
            fclose(arquivo);
            free(cliente);
            free(cpf);
            return 1;
        }
    }

    fclose(arquivo); 
    free(cliente);
    free(cpf);
    return -1;
}