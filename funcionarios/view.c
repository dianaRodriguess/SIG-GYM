#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "model.h"

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
    printf("|\t\t\033[1m-> Dados do Funcionario\033[m \n");
    printf("\033[1m|Nome:\033[m %s\n", funcionario->nome);
    printf("\033[1m|CPF:\033[m %s\n", funcionario->cpf);
    printf("\033[1m|Telefone:\033[m %s\n", funcionario->telefone);
    printf("\033[1m|Email:\033[m %s\n", funcionario->email);
    printf("\033[1m|Data de nascimento:\033[m %s\n", funcionario->dataNasc);
    printf("\033[1m|Plano:\033[m %s\n", nomeCargo(funcionario->cargo));
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}

char relatorioFuncionarios(void){
    limparTela();
    char opcao;
    printf("-------------------------------------------------------\n");
    printf("|                       Relatório                     |\n");
    printf("-------------------------------------------------------\n");
    printf("|              1 - Status do funcionário              |\n");
    printf("|              2 - Funcionário por cargo              |\n");
    printf("|              3 - Funcionários por ordem alf.        |\n");
    printf("|              0 - Retornar ao Menu Principal         |\n");
    printf("-------------------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

char statusFuncionarios(void){
    limparTela();
    char opcao;
    printf("-------------------------------------------------------\n");
    printf("|                   Relatório - Status                |\n");
    printf("-------------------------------------------------------\n");
    printf("|              1 - Funcionários ativos                |\n");
    printf("|              2 - Funcionários inativos              |\n");
    printf("|              3 - Todos os funcionários              |\n");
    printf("|              0 - Retornar ao Menu Principal         |\n");
    printf("-------------------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

char cargoFuncionarios(void){
    limparTela();
    char opcao;
    printf("-------------------------------------------------------\n");
    printf("|                   Relatório - Planos                |\n");
    printf("-------------------------------------------------------\n");
    printf("|                 1 - Gerentes                        |\n");
    printf("|                 2 - Professores                     |\n");
    printf("|                 3 - ASG's                           |\n");
    printf("|                 3 - Atendentes                      |\n");
    printf("|                 0 - Retornar ao Menu Principal      |\n");
    printf("-------------------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;                  
}

