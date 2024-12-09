#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/leitura_dados.h"
#include "../libs/utils.h"
#include "model.h"
#include "view.h"
#include "controller.h"

char* cancaleOperacao(char* op, Cliente* cliente){
    if(op == NULL){
        printf("Operação cancelada.\n");
        pausarTela();
        free(cliente);
        free(op);
        return NULL;
    }
    return op;
}

Cliente* cadastrarCliente(void){
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    if(cliente == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    cadastrarClientes();

    char* cpf = leCPF();
    cpf = cancaleOperacao(cpf, cliente);
    if(cpf == NULL) return NULL;
    strcpy(cliente->cpf, cpf);
    free(cpf);

    char* nome = leNome();
    nome = cancaleOperacao(nome, cliente);
    if(nome == NULL) return NULL;
    strcpy(cliente->nome, nome);
    free(nome);

    char* telefone = leTelefone();
    telefone = cancaleOperacao(telefone, cliente);
    if(telefone == NULL) return NULL;
    strcpy(cliente->telefone, telefone);

    char* email = leEmail();
    email = cancaleOperacao(email, cliente);
    if(email == NULL) return NULL;
    strcpy(cliente->email, email);

    char* dataNasc = leDataNasc();
    dataNasc = cancaleOperacao(dataNasc, cliente);
    if(dataNasc == NULL) return NULL;
    strcpy(cliente->dataNasc, dataNasc);

    char* sexo = leSexo();
    sexo = cancaleOperacao(sexo, cliente);
    if(sexo == NULL) return NULL;
    cliente->sexo = *sexo;

    char* plano = lePlano();
    plano = cancaleOperacao(plano, cliente);
    if(plano == NULL) return NULL;
    cliente->plano = *plano;

    cliente->status = 1;

    return cliente;
}

void listarDados(void){
    char* cpf = leCPF();
    Cliente* cliente = carregarClientes(cpf);
    if (cliente == NULL) {
        printf("Cliente não encontrado ou não está ativo.\n");
        free(cliente);
        free(cpf);
        return;
    }

    dadosClientes(cliente);

    free(cliente);
    free(cpf);
}

void atualizarCliente(void) {
    Cliente cliente;

    menuAtualizarCliente();
    capturarCPF(cliente.cpf);

    printf("|_____________________________________________|\n");
}

void deletarCliente(void) {
    Cliente cliente;
    
    menuDeletarCliente();
    capturarCPF(cliente.cpf);

    printf("|_____________________________________________|\n");
}
