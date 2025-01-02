#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "model.h"
#include "../libs/utils.h"


char menuFuncionarios(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                Funcionários                |\n");
    printf("----------------------------------------------\n");
    printf("|             1 - Cadastre - se              |\n");
    printf("|             2 - Exibir Dados               |\n");
    printf("|             3 - Alterar Dados              |\n");
    printf("|             4 - Excluir Funcionário        |\n");
    printf("|             0 - Retornar ao Menu Principal |\n");
    printf("----------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

void telaCadastrarFuncionario(void){
    limparTela();
    printf("------------------------------------------------\n");
    printf("|             Cadastro de Funcinarios           |\n");
    printf("------------------------------------------------\n");

    
}

void numDadosCad(void){
    limparTela();
    printf("--------------------------------------------------------------------------------------\n");
    printf("|                                   Cadastrar Dados                                  |\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("| 1 - Nome | 2 - CPF | 3 - Telefone | 4 - Email | 5 - Data de Nascimento | 6 - Cargo |\n");
    printf("--------------------------------------------------------------------------------------\n");
}

void numDadosFun(void){
    limparTela();
    printf("--------------------------------------------------------------------------------------\n");
    printf("|                                     Alterar Dados                                  |\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("| 1 - Nome | 2 - CPF | 3 - Telefone | 4 - Email | 5 - Data de Nascimento | 6 - Cargo |\n");
    printf("--------------------------------------------------------------------------------------\n");
}

void telaExibirDados(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                 Exibir Dados               |\n");
    printf("----------------------------------------------\n");
}

void telaAlterarDados(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                 Alterar Dados              |\n");
    printf("----------------------------------------------\n");
}

void telaExcluirFuncionario(void){
    limparTela();
    printf("--------------------------------------------------\n");
    printf("|               Excluir Funcionário              |\n");
    printf("--------------------------------------------------\n");
}

void dadosFuncionarios(Funcionario* funcionario){
    limparTela();
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| Nome: %s \n", funcionario->nome);
    printf("| CPF: %s \n", funcionario->cpf);
    printf("| Telefone: %s \n", funcionario->telefone);
    printf("| Email: %s \n", funcionario->email);
    printf("| Data de Nascimento: %s\n", funcionario->dataNasc);
    printf("| Plano: %s \n", nomeCargo(funcionario->cargo));
    printf("----------------------------------------------------------------------------------------------------\n");
}