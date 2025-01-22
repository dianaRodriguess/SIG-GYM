#include <stdio.h>
#include <stdlib.h>
#include "view.h"


char menuTreinos(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                  Treinos                   |\n");
    printf("----------------------------------------------\n");
    printf("|             1 - Cadastrar Treino           |\n");
    printf("|             2 - Pesquisar Treino           |\n");
    printf("|             3 - Atualizar Treino           |\n");
    printf("|             4 - Deletar Treino             |\n");
    printf("|             0 - Retornar ao Menu Principal |\n");
    printf("----------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

void menuCadastrarTreino(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|             Cadastro de Treino              |\n");
    printf("----------------------------------------------\n");
}

void menuExibirTreino(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                Exibir Treino               |\n");
    printf("----------------------------------------------\n");
}

void menuAtualizarTreino(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                Alterar Treino              |\n");
    printf("----------------------------------------------\n");
}

void menuDeletarTreino(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                Deletar Treino              |\n");
    printf("----------------------------------------------\n");
}
