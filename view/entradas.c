#include <stdio.h>
#include <stdlib.h>

void capturarNome(char *nome){
    printf("> Nome: \n");
    fgets(nome, 55, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

void capturarCPF(char *cpf){
    printf("> CPF: \n");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
}

void capturarEndereco(char *endereco){
    printf("> Endereço: \n");
    fgets(endereco, 55, stdin);
    endereco[strcspn(endereco, "\n")] = '\0';
}

void capturarTelefone(char *telefone){
    printf("> Telefone: \n");
    fgets(telefone, 15, stdin);
    telefone[strcspn(telefone, "\n")] = '\0';
}

void capturarEmail(char *email){
    printf("> Email: \n");
    fgets(email, 55, stdin);
    email[strcspn(email, "\n")] = '\0';
}

void capturarDataNasc(char *dataNasc){
    printf("> Data de nascimento: \n");
    fgets(dataNasc, 11, stdin);
    dataNasc[strcspn(dataNasc, "\n")] = '\0';
}

void capturarSexo(char *sexo){
    printf("> Sexo: \n");
    fgets(sexo, 11, stdin);
    sexo[strcspn(sexo, "\n")] = '\0';
}