#include <stdio.h>
#include <stdlib.h>
#include "view.h"

char menuFuncionario(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                  Funcionários              |\n");
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
void menuCadastrarFuncionario(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|            Cadastro de Funcionário          |\n");
    printf("----------------------------------------------\n");
}

void menuPesquisarFuncionario(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|            Pesquisar Funcionário           |\n");
    printf("----------------------------------------------\n");
}

void menuAtualizarFuncionario(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|             Atualizar Funcionário          |\n");
    printf("----------------------------------------------\n");
}

void menuDeletarFuncionario(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|              Deletar Funcionáro            |\n");
    printf("----------------------------------------------\n");
}