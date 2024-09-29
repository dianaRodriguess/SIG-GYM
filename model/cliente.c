#include <stdio.h>
#include <stdlib.h>

void cadastrarCliente(void){
    system("clear");
    printf(" __________________________________ \n");
    printf("|.....   CADASTRAR CLIENTE    .....|\n");
    printf("|__________________________________|\n");
    printf("> Nome: \n");
    printf("> CPF: \n");
    printf("> Endereço: \n");
    printf("> Telefone: \n");
    printf("> Email: \n");
    printf("> Data de nascimento: \n");
    printf("> Sexo: \n");
    printf("> Plano: \n");
    printf("> Tecle <ENTER> para continuar...\n");
    printf("|__________________________________|\n");
    getchar();
}

void pesquisarCliente(void){
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... PESQUISAR CLIENTE ...  .  .....|\n");
    printf(" _____________________________________________|\n");
    printf("\n>Digite o CPF do cliente (apenas números): \n");
    printf("\n> Tecle <ENTER> para continuar...\n");
    printf("|_____________________________________________|\n");
    getchar();
}

void atualizarCliente(void){
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... ATUALIZAR CLIENTE ...  .  .....|\n");
    printf(" _____________________________________________|\n");
    printf("\n>Digite o CPF do cliente (apenas números): \n");
    printf("\n> Tecle <ENTER> para continuar...\n");
    printf("|_____________________________________________|\n");
    getchar();
}

void deletarCliente(void){
    system("clear");
    printf("|___________________________________________|\n");
    printf("|.....  .  ... DELETAR CLIENTE ...  .  .....|\n");
    printf(" ___________________________________________|\n");
    printf("\n>Digite o CPF do cliente (apenas números): \n");
    printf("\n> Tecle <ENTER> para continuar...\n");
    printf("|___________________________________________|\n");
    getchar();
}