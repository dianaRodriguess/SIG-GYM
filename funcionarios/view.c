#include <stdio.h>
#include <stdlib.h>
#include "view.h"


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

void menuCadastrarFuncionario(void){
    system("clear");
    printf("|_________________________________________________|\n");
    printf("|.....  .  ... CADASTRAR FUNCIONÁRIO ...  .  .....|\n");
    printf("|_________________________________________________|\n");
}

void menuPesquisarFuncionario(void){
    system("clear");
    printf("|_________________________________________________|\n");
    printf("|.....  .  ... PESQUISAR FUNCIONÁRIO ...  .  .....|\n");
    printf("|_________________________________________________|\n");
}

void menuAtualizarFuncionario(void){
    system("clear");
    printf("|_________________________________________________|\n");
    printf("|.....  .  ... ATUALIZAR FUNCIONÁRIO ...  .  .....|\n");
    printf("|_________________________________________________|\n");
}

void menuDeletarFuncionario(void){
    system("clear");
    printf("|_________________________________________________|\n");
    printf("|......  .  ... DELETAR FUNCIONÁRIO ...  .  ......|\n");
    printf("|_________________________________________________|\n");
}