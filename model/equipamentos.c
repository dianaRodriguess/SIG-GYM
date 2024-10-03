#include <stdio.h>
#include <stdlib.h>

void cadastrarEquipamento(void){
    system("clear");
    printf("|_________________________________________________|\n");
    printf("|.....  .  ... CADASTRAR EQUIPAMENTO ...  .  .....|\n");
    printf(" _________________________________________________|\n");
    printf("> Nome: \n");
    printf("> Função: \n");
    printf("> Marca: \n");
    printf("> Preço: \n");
    printf("> Fabricante: \n");
    printf("> Quantidade: \n");
    printf("> Código de barras: \n");
    printf("\n> Tecle <0> para continuar...\n");
    printf("|________________________________________________|\n");
}

void pesquisarEquipamento(void){
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . .... PESQUISAR EQUIPAMENTO .... . ...  .  .....|\n");
    printf(" _______________________________________________________________|\n");
    printf("\n>Digite o Código de barras do equipamento (apenas números): \n");
    printf("\n> Tecle <0> para continuar...\n");
    printf("|_______________________________________________________________|\n");
}

void atualizarEquipamento(void){
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . .... ATUALIZAR EQUIPAMENTO .... . ...  .  .....|\n");
    printf("|_______________________________________________________________|\n");
    printf("\n>Digite o Código de barras do equipamento (apenas números): \n");
    printf("\n> Tecle <0> para continuar...\n");
    printf("|_______________________________________________________________|\n");
}

void deletarEquipamento(void){
    system("clear");
    printf("|_____________________________________________________________|\n");
    printf("|.....  .  ... . .... DELETAR EQUIPAMENTO .... . ...  .  .....|\n");
    printf("|_____________________________________________________________|\n");
    printf("\n>Digite o Código de barras do equipamento (apenas números): \n");
    printf("\n> Tecle <0> para continuar...\n");
    printf("|_____________________________________________________________|\n");
}