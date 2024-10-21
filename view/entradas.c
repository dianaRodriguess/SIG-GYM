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