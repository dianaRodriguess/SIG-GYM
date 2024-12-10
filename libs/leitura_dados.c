#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "entradas.h"
#include "../clientes/model.h"

char* leNome(void) {
    int valido = 0;
    int tamanho;
    char* nome = (char*)malloc(61 * sizeof(char));
    
    do {
        capturarNome(nome);
        tamanho = strlen(nome);

        if(strcmp(nome, "0") == 0){
            return NULL;
        }

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

    return nome;
}

char* leCPF(void) {
    int valido = 0;
    char* cpf = (char*)malloc(15 * sizeof(char));

    do {
        capturarCPF(cpf);

        if(strcmp(cpf, "0") == 0){
            return NULL;
        }

        if (!validaCpf(cpf)) {
            printf("CPF inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return cpf;
}

char* leTelefone(void) {
    int valido = 0;
    char* telefone = (char*)malloc(15 * sizeof(char));

    do {
        capturarTelefone(telefone);

        if(strcmp(telefone, "0") == 0){
            return NULL;
        }

        if (!validaTelefone(telefone)) {
            printf("Telefone inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return telefone;
}

char* leEmail(void) {
    int valido = 0;
    char* email = (char*)malloc(55 * sizeof(char));

    do {
        capturarEmail(email);

        if(strcmp(email, "0") == 0){
            return NULL;
        }

        if (!validaEmail(email)) {
            printf("Email inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return email;
}

char* leSexo(void) {
    int valido = 0;
    char* sexo = (char*)malloc(sizeof(char));

    do {
        capturarSexo(sexo);

        if(strcmp(sexo, "0") == 0){
            return NULL;
        }

        if (*sexo != 'M' && *sexo != 'F') {
            printf("Sexo inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return sexo;
}

char* lePlano(void) {
    int valido = 0;
    char* plano = (char*)malloc(sizeof(char));

    do {
        capturarPlano(plano);

        if(strcmp(plano, "0") == 0){
            return NULL;
        }

        if (!verificaPlano(atoi(plano))) {
            printf("Plano inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return plano;
}

char* leDataNasc(void) {
    int valido = 0;
    char* dataNasc = (char*)malloc(11 * sizeof(char));

    do {
        capturarDataNasc(dataNasc);

        if(strcmp(dataNasc, "0") == 0){
            return NULL;
        }

        if (!validaData(dataNasc)) {
            printf("Data de nascimento inválida, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return dataNasc;
}