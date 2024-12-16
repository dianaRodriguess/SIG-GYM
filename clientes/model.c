#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "view.h"
#include "../libs/utils.h"
#include "../libs/style.h"
#include "../libs/leitura_dados.h"

int salvarCliente(Cliente* cliente){
    FILE* arquivo = fopen("clientes.dat", "ab");
    if(arquivo == NULL){
         return 0;
    }
    if(fwrite(cliente, sizeof(Cliente), 1, arquivo) != 1){
        return -1;
    }
    fclose(arquivo);
    return 1;
}

Cliente* carregarClientes(char* cpf){
    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente));
    FILE* arquivo = fopen("clientes.dat", "rb");
    if(arquivo == NULL) {
        return NULL;
    }

    while(fread(cliente, sizeof(Cliente), 1, arquivo)) {
    if ((!strcmp(cliente->cpf, cpf)) && (cliente->status == 1)) {
        fclose(arquivo);
        return cliente;
    }
    }
    fclose(arquivo);
    free(cliente);
    return NULL;
}

int regravaCliente(Cliente* cliente){
    FILE* arquivo = fopen("clientes.dat", "r+b");
    if(arquivo == NULL){
        return 0; // Erro na abertura do arquivo
    }

    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    while (fread(novoCliente, sizeof(Cliente), 1, arquivo)) {
        if (!strcmp(novoCliente->cpf, cliente->cpf)) {
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            if(fwrite(cliente, sizeof(Cliente), 1, arquivo)){
                fclose(arquivo);
                free(novoCliente);
                return 1; // Sucesso
            }
            fclose(arquivo);
            free(novoCliente);
            return -1; // Erro na escrita
        }
    }
    fclose(arquivo);
    free(novoCliente);
    return -2; // Cliente não encontrado
}

int excluirCliente(Cliente* cliente, char* cpf){
    FILE* arquivo = fopen("clientes.dat", "r+b");
    if(arquivo == NULL){
        return 0;
    }

    while(fread(cliente, sizeof(Cliente), 1, arquivo)){
        if(!strcmp(cliente->cpf, cpf) && cliente->status == 1){
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            cliente->status = 0;
            if(fwrite(cliente, sizeof(Cliente), 1, arquivo)){
                fclose(arquivo);
                return 1;
            }
            fclose(arquivo);
            return -1;   
        }
    }
    fclose(arquivo); 
    return -2;
}

void alteraCliente(Cliente* cliente, int op){
    char* entrada;
    int opcao;
    int resultado;

    switch(op){
        case 1:
            limparBuffer();
            entrada = leNome();
            strcpy(cliente->nome, entrada);
            break;
        case 2:
            limparBuffer();
            entrada = leCPF();
            strcpy(cliente->cpf, entrada);
            break;
        case 3:
            limparBuffer();
            entrada = leTelefone();
            strcpy(cliente->telefone, entrada);
            break;
        case 4:
            limparBuffer();
            entrada = leEmail();
            strcpy(cliente->email, entrada);
            break;
        case 5:
            limparBuffer();
            entrada = leDataNasc();
            strcpy(cliente->dataNasc, entrada);
            break;
        case 6:
            limparBuffer();
            opcao = leSexo();
            cliente->sexo = opcao;
            break;
        case 7:
            limparBuffer();
            opcao = lePlano();
            cliente->plano = opcao;
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    resultado = regravaCliente(cliente);
    dadosClientes(cliente);
    msgManipCliente("regravarClientes", resultado);
    free(entrada);
}