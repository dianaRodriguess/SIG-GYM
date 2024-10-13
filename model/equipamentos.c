#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarEquipamento(void){
    char nome[55], funcao[27], marca[27], preco[9], fabricante[27];
    char quantidade[9], codBarras[13];
    system("clear");
    printf("|_________________________________________________|\n");
    printf("|.....  .  ... CADASTRAR EQUIPAMENTO ...  .  .....|\n");
    printf(" _________________________________________________|\n");
    printf("> Nome: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("> Função: \n");
    fgets(funcao, sizeof(funcao), stdin);
    funcao[strcspn(funcao, "\n")] = '\0';

    printf("> Marca: \n");
    fgets(marca, sizeof(marca), stdin);
    marca[strcspn(marca, "\n")] = '\0';

    printf("> Preço: \n");
    fgets(preco, sizeof(preco), stdin);
    preco[strcspn(preco, "\n")] = '\0';

    printf("> Fabricante: \n");
    fgets(fabricante, sizeof(fabricante), stdin);
    fabricante[strcspn(fabricante, "\n")] = '\0';

    printf("> Quantidade: \n");
    fgets(quantidade, sizeof(quantidade), stdin);
    quantidade[strcspn(quantidade, "\n")] = '\0';

    printf("> Código de barras: \n");
    fgets(codBarras, sizeof(codBarras), stdin);
    codBarras[strcspn(codBarras, "\n")] = '\0';
    printf("|________________________________________________|\n");
}

void pesquisarEquipamento(void){
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . .... PESQUISAR EQUIPAMENTO .... . ...  .  .....|\n");
    printf(" _______________________________________________________________|\n");
    printf("\n>Digite o Código de barras do equipamento (apenas números): \n");
    printf("|_______________________________________________________________|\n");
}

void atualizarEquipamento(void){
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . .... ATUALIZAR EQUIPAMENTO .... . ...  .  .....|\n");
    printf("|_______________________________________________________________|\n");
    printf("\n>Digite o Código de barras do equipamento (apenas números): \n");
    printf("|_______________________________________________________________|\n");
}

void deletarEquipamento(void){
    system("clear");
    printf("|_____________________________________________________________|\n");
    printf("|.....  .  ... . .... DELETAR EQUIPAMENTO .... . ...  .  .....|\n");
    printf("|_____________________________________________________________|\n");
    printf("\n>Digite o Código de barras do equipamento (apenas números): \n");
    printf("|_____________________________________________________________|\n");
}