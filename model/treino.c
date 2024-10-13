#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarTreino(void){
    char nome [55], musculos [62], repeticao [32], cliente [15];
    system("clear");
    printf("|__________________________________________________________|\n");
    printf("|.....  .  ... . .... CADASTRAR TREINO .... . ...  .  .....|\n");
    printf(" __________________________________________________________|\n");
    printf("> Nome: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("> Musculos a serem treinados: \n");
    fgets(musculos, sizeof(musculos), stdin);
    musculos[strcspn(musculos, "\n")] = '\0';

    printf("> Repetição: \n");
    fgets(repeticao, sizeof(repeticao), stdin);
    repeticao[strcspn(repeticao, "\n")] = '\0';

    printf("> CPF do cliente: \n");
    fgets(cliente, sizeof(cliente), stdin);
    cliente[strcspn(cliente, "\n")] = '\0';
    printf("|__________________________________________________________|\n");
}

void atualizarTreino(void){
    char codigo [6];
    system("clear");
    printf("|__________________________________________________________|\n");
    printf("|.....  .  ... . .... ATUALIZAR TREINO .... . ...  .  .....|\n");
    printf(" __________________________________________________________|\n");
    printf("\n>Digite o Código do treino (apenas números): \n");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';
    printf("|__________________________________________________________|\n");
}
void pesquisarTreino(void){
    system("clear");
    printf("|__________________________________________________________|\n");
    printf("|.....  .  ... . .... PESQUISAR TREINO .... . ...  .  .....|\n");
    printf(" __________________________________________________________|\n");
    printf("\n>Digite o Código do treino (apenas números): \n");
    printf("|__________________________________________________________|\n");
}
void deletarTreino(void){
    system("clear");
    printf("|__________________________________________________________|\n");
    printf("|.....  .  ... . ....  DELETAR TREINO  .... . ...  .  .....|\n");
    printf(" __________________________________________________________|\n");
    printf("\n>Digite o Código do treino (apenas números): \n");
    printf("|__________________________________________________________|\n");
}