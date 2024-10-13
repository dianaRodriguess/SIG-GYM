#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarFuncionario(void){
    char nome [55], cpf [15], endereco [55], telefone [15], email [55], dataNasc [11];
    char cargo [22];
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . .... CADASTRAR FUNCIONÁRIO .... . ...  .  .....|\n");
    printf("|_______________________________________________________________|\n");
    printf("> Nome: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("> CPF: \n");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    printf("> Endereço: \n");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = '\0';

    printf("> Telefone: \n");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    printf("> Email: \n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("> Data de nascimento: \n");
    fgets(dataNasc, sizeof(dataNasc), stdin);
    dataNasc[strcspn(dataNasc, "\n")] = '\0';

    printf("> Cargo: \n");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = '\0';
    printf("|_______________________________________________________________|\n");

}

void pesquisarFuncionario(void){
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . .... PESQUISAR FUNCIONÁRIO .... . ...  .  .....|\n");
    printf("|_______________________________________________________________|\n");
    printf("\n>Digite o CPF do funcionário (apenas números): \n");
    printf("|_______________________________________________________________|\n");
}

void atualizarFuncionario(void){
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . .... ATUALIZAR FUNCIONÁRIO .... . ...  .  .....|\n");
    printf("|_______________________________________________________________|\n");
    printf("\n>Digite o CPF do funcionário (apenas números): \n");
    printf("|_______________________________________________________________|\n");
}

void deletarFuncionario(void){
    system("clear");
    printf("|_______________________________________________________________|\n");
    printf("|.....  .  ... . ....  DELETAR FUNCIONÁRIO  .... . ...  .  .....|\n");
    printf("|_______________________________________________________________|\n");
    printf("\n>Digite o CPF do funcionário (apenas números): \n");
    printf("|_______________________________________________________________|\n");

}