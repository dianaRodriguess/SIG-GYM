#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "entradas.h"
#include "../clientes/model.h"
#include "../funcionarios/model.h"

char* leNome(void) {
    int valido = 0;
    int tamanho;
    char* nome = (char*)malloc(61 * sizeof(char));
    
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

    return nome;
}

char* leCPF(void) {
    int valido = 0;
    char* cpf = (char*)malloc(15 * sizeof(char));

    do {
        capturarCPF(cpf);

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

        if (!validaEmail(email)) {
            printf("Email inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return email;
}

int leSexo(void) {
    int valido = 0;
    int sexo;

    do {
        capturarSexo(&sexo);

        if (sexo != 1 && sexo != 2) {
            printf("Sexo inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return sexo;
}

int lePlano(void) {
    int valido = 0;
    int plano;

    do {
        capturarPlano(&plano);

        if (!verificaPlano(plano)) {
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

        if (!validaData(dataNasc)) {
            printf("Data de nascimento inválida, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return dataNasc;
}

char* leMarca(void){
    int valido = 0;
    int tamanho;
    char* marca = (char*)malloc(27 * sizeof(char));

    do{
        capturarMarca(marca);
        tamanho = strlen(marca);

        if (tamanho == 0){
            printf("Marca inválida. Por favor, insira uma marca correta.\n");
            continue; 
        }

        if(!validaName(marca, tamanho)){
            printf("Marca inválida. Tente novamente.\n");
        } else{
            valido = 1;
        }
    } while(!valido);

    return marca;
}
int leCargo(void) {
    int valido = 0;
    int cargo;

    do {
        capturarCargo(&cargo);

        if (!verificaPlano(cargo)) {
            printf("Cargo inválido, tente novamente.\n");
        } else {
            valido = 1;
        }
    } while(!valido);

    return cargo;
}

char* leFuncao(void){
    int valido = 0;
    int tamanho;
    char* funcao = (char*)malloc(100 * sizeof(char));

    do{
        capturarFuncao(funcao);
        tamanho = strlen(funcao);

        if (tamanho == 0){
            printf("Função inválida. Por favor, insira uma descrição correta.\n");
            continue; 
        }

        if(!validaName(funcao, tamanho)){
            printf("Descrição inválida. Tente novamente.\n");
        } else{
            valido = 1;
        }
    } while(!valido);
    
    return funcao;
}

int leQuantidade(void) {
    int quantidade_i;
    int valido = 0;
    int tamanho;
    char quantidade[11];

    do {
        capturarQuantidade(quantidade);
        tamanho = strlen(quantidade);

        if (tamanho == 0) {
            printf("Quantidade inválida. Por favor, insira um valor correto.\n");
            continue; 
        }

        if (!validaQuantidade(quantidade)) {
            printf("Quantidade inválida. Tente novamente.\n");
        } else {
            quantidade_i = atoi(quantidade);
            valido = 1;
        }
    } while (!valido);

    return quantidade_i;
}

float lePreco(void) {
    float preco_f;
    int valido = 0;
    int tamanho;
    char preco[13];

    do {
        capturarPreco(preco);
        tamanho = strlen(preco);

        if (tamanho == 0) {
            printf("Preço inválido. Por favor, insira um valor correto.\n");
            continue; 
        }

        if (!checaPreco(preco)) {
            printf("Preço inválido. Tente novamente.\n");
        } else {
            preco_f = strtof(preco, NULL);
            valido = 1;
        }
    } while (!valido);

    return preco_f;
}

int leID(void) {
    char id[6];
    int id_i;
    int valido = 0;
    char *endptr;

    do {
        capturarIDequi(id);

        if (strlen(id) == 0) {
            printf("ID inválido. Por favor, insira um valor correto.\n");
            continue;
        }

        if (!validaQuantidade(id)) {
            printf("ID inválido. Tente novamente.\n");
            continue;
        } else {
            id_i = strtol(id, &endptr, 10);
            if (*endptr != '\0') { 
                printf("Entrada inválida! Apenas números são permitidos.\n");
                continue;
            }
            valido = 1;
        }
    } while (!valido);

    return id_i;
}

char* leNomeEqui(void) {
    int valido = 0;
    int tamanho;
    char* nome = (char*)malloc(31 * sizeof(char));
    
    do {
        capturarNomeEqui(nome);
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

    return nome;
}