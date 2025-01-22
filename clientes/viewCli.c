#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewCli.h"
#include "modelCli.h"
#include "../libs/utils.h"

char menuClientes(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                  Clientes                  |\n");
    printf("----------------------------------------------\n");
    printf("|             1 - Cadastre - se              |\n");
    printf("|             2 - Exibir Dados               |\n");
    printf("|             3 - Alterar Dados              |\n");
    printf("|             4 - Excluir Cliente            |\n");
    printf("|             0 - Retornar ao Menu Principal |\n");
    printf("----------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

void cadastrarClientes(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|             Cadastro de Clientes           |\n");
    printf("----------------------------------------------\n");
}

void exibirDados(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                 Exibir Dados               |\n");
    printf("----------------------------------------------\n");
}

void alterarDados(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                 Alterar Dados              |\n");
    printf("----------------------------------------------\n");
}

void cadDados(void) {
    limparTela();
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("|                                         Cadastrar Dados                                       |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| 1 - Nome | 2 - CPF | 3 - Telefone | 4 - Email | 5 - Data de Nascimento | 6 - Sexo | 7 - Plano |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
}

void numDados(void) {
    limparTela();
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("|                                           Alterar Dados                                       |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| 1 - Nome | 2 - CPF | 3 - Telefone | 4 - Email | 5 - Data de Nascimento | 6 - Sexo | 7 - Plano |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
}

void excluiClientes(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|               Excluir Cliente              |\n");
    printf("----------------------------------------------\n");
}

void dadosClientes(Cliente* cliente){
    limparTela();
    printf("|\t\t\033[1m-> Dados do Usuário\033[m \n");
    printf("\033[1m|Nome:\033[m %s\n", cliente->nome);
    printf("\033[1m|CPF:\033[m %s\n", cliente->cpf);
    printf("\033[1m|Telefone:\033[m %s\n", cliente->telefone);
    printf("\033[1m|Email:\033[m %s\n", cliente->email);
    printf("\033[1m|Data de nascimento:\033[m %s\n", cliente->dataNasc);
    printf("\033[1m|Sexo:\033[m %s\n", nomeSexo(cliente->sexo));
    printf("\033[1m|Plano:\033[m %s\n", nomePlano(cliente->plano));
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}

