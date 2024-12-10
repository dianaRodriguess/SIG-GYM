#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "model.h"


void menuCadastrarCliente(void){
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... CADASTRAR CLIENTE ...  .  .....|\n");
    printf("|_____________________________________________|\n");
}

void menuPesquisarCliente(void){
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... PESQUISAR CLIENTE ...  .  .....|\n");
    printf("|_____________________________________________|\n");
}

void menuAtualizarCliente(void){
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... ATUALIZAR CLIENTE ...  .  .....|\n");
    printf("|_____________________________________________|\n");
}

void menuDeletarCliente(void){
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|......  .  ... DELETAR CLIENTE ...  .  ......|\n");
    printf("|_____________________________________________|\n");
}

void mostrarEquipamentos(Cliente* cli){
    
    printf("\n... INFORMAÇÕES DO CLIENTE ...\n");

    printf(">> Nome: %s\n", cli->nome);
    printf(">> CPF: %s\n", cli->cpf);
    printf(">> Telefone: %s\n", cli->telefone);
    printf(">> Email: %s\n", cli->email);
    printf(">> Data de Nascimento: %s\n", cli->dataNasc);
    printf(">> Plano: %c\n", cli->plano);
    printf(">> Sexo: %c\n", cli->sexo);
    printf(">> Status: %d\n", cli->status);
    printf("|________________________________________________|\n");
}
