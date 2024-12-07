#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "../view/entradas.h"
#include "../clientes/model.h"

void leNome(char* nome) {
    int valido = 0;
    int tamanho;
    
    do {
        capturarNome(nome);
        tamanho = strlen(nome);

        if (tamanho == 0) {
            printf("Nome inválido. Por favor, insira um nome.\n");
            continue; 
        }

        if (!validaName(nome, tamanho)) {
            printf("Nome inválido, tente novamente.\n");
        } else {
            valido = 1;  
        }
    } while(!valido);
}

void leCPF(char* cpf) {
    int valido = 0;

    do {
        capturarCPF(cpf);

        if (!validaCpf(cpf)) {
            printf("CPF inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);
}

void leTelefone(char* telefone) {
    int valido = 0;

    do {
        capturarTelefone(telefone);

        if (!validaTelefone(telefone)) {
            printf("Telefone inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);
}

void leEmail(char* email) {
    int valido = 0;

    do {
        capturarEmail(email);

        if (!validaEmail(email)) {
            printf("Email inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);
}

void leSexo(char* sexo) {
    int valido = 0;

    do {
        capturarSexo(sexo);

        if (*sexo != 'M' && *sexo != 'F') {
            printf("Sexo inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);
}

void lePlano(char* plano) {
    int valido = 0;

    do {
        capturarPlano(plano);

        if (!verificaPlano(atoi(plano))) {
            printf("Plano inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);
}