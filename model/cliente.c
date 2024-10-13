#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "../controller/entradas.h"

void cadastrarCliente(void){
    char nome [55], cpf [15], endereco [55], telefone [15], email [55], dataNasc [11];
    char sexo, plano;
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... CADASTRAR CLIENTE ...  .  .....|\n");
    printf(" _____________________________________________|\n");
    printf("> Nome: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("> CPF (somente números): \n");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    
    printf("> Endereço (só letras e números): \n");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = '\0';
    
    printf("> Telefone (somente números): \n");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';
   
    printf("> Email: \n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    
    printf("> Data de nascimento (xx/xx/xxxx): \n");
    fgets(dataNasc, sizeof(dataNasc), stdin);
    dataNasc[strcspn(dataNasc, "\n")] = '\0';
    
    printf("> Sexo (M/F): \n");
    scanf("%[a-zA-Z]", &sexo);
    limparBuffer();
    
    printf("> Plano.: \n1 - Básico \n2 - Intermediário \n3 - Avançado.: \n");
    scanf("%[0-9]", &plano);
    limparBuffer();
    printf("|_____________________________________________|\n");
}

void pesquisarCliente(void){
    char cpf [15];
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... PESQUISAR CLIENTE ...  .  .....|\n");
    printf(" _____________________________________________|\n");
    printf("\n>Digite o CPF do cliente (apenas números): \n");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    printf("|_____________________________________________|\n");
}

void atualizarCliente(void){
    system("clear");
    printf("|_____________________________________________|\n");
    printf("|.....  .  ... ATUALIZAR CLIENTE ...  .  .....|\n");
    printf(" _____________________________________________|\n");
    printf("\n>Digite o CPF do cliente (apenas números): \n");
    printf("|_____________________________________________|\n");
}

void deletarCliente(void){
    system("clear");
    printf("|___________________________________________|\n");
    printf("|.....  .  ... DELETAR CLIENTE ...  .  .....|\n");
    printf(" ___________________________________________|\n");
    printf("\n>Digite o CPF do cliente (apenas números): \n");
    printf("|___________________________________________|\n");
}