#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "model.h"
#include "../libs/utils.h"


char menuExercicios(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                  Exercícios                |\n");
    printf("----------------------------------------------\n");
    printf("|             1 - Cadastrar Exercício        |\n");
    printf("|             2 - Pesquisar Exercício        |\n");
    printf("|             3 - Atualizar Exercício        |\n");
    printf("|             4 - Excluir exercício          |\n");
    printf("|             5 - Relatórios                 |\n");
    printf("|             0 - Retornar ao Menu Principal |\n");
    printf("----------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

void menuCadastrarExercicio(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|             Cadastro de Exercicio          |\n");
    printf("----------------------------------------------\n");
}

void menuExibirExercicio(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|               Exibir Exercicio             |\n");
    printf("----------------------------------------------\n");
}

void menuAtualizarExercicio(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|               Alterar Exercicio            |\n");
    printf("----------------------------------------------\n");
}

void menuDeletarExercicio(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|               Deletar Exercicio            |\n");
    printf("----------------------------------------------\n");
}

void dadosExercicios(Exercicio* exercicio){
    limparTela();
    printf("|\t\t\033[1m-> Dados do Exercício\033[m \n");
    printf("\033[1m|Nome:\033[m %s\n", exercicio->nome);
    printf("\033[1m|ID:\033[m %d\n", exercicio->id_exercicio);
    printf("\033[1m|Categoria:\033[m %s\n", exercicio->categoria);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}

char relatorioExercicio(void){
    limparTela();
    char opcao;
    printf("-------------------------------------------------------\n");
    printf("|                       Relatório                     |\n");
    printf("-------------------------------------------------------\n");
    printf("|              1 - Status dos exercícios              |\n");
    printf("|              2 - Exercícios por ordem alf.          |\n");
    printf("|              0 - Retornar ao Menu Principal         |\n");
    printf("-------------------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}


char statusExercicios(void){
    limparTela();
    char opcao;
    printf("-------------------------------------------------------\n");
    printf("|                   Relatório - Status                |\n");
    printf("-------------------------------------------------------\n");
    printf("|              1 - Exercícios ativos                  |\n");
    printf("|              2 - Exercícios inativos                |\n");
    printf("|              3 - Todos os exercícios                |\n");
    printf("|              0 - Retornar ao Menu Principal         |\n");
    printf("-------------------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}