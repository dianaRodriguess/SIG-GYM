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
    char* marca = (char*)malloc(50 * sizeof(char));
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
char* leQuantidade(void) {
    int valido = 0;
    int tamanho;
    char* quantidade = (char*)malloc(21 * sizeof(char)); // 20 caracteres + 1 para '\0'
    do {
        capturarQuantidade(quantidade); // Função já existente para capturar a entrada do usuário
        tamanho = strlen(quantidade);
        if (tamanho == 0) {
            printf("Quantidade inválida. Por favor, insira um valor correto.\n");
            continue; 
        }
        if (!validaQuantidade(quantidade)) {
            printf("Quantidade inválida. Tente novamente.\n");
        } else {
            valido = 1;
        }
    } while (!valido);
    return quantidade;
}
char* lePreco(void) {
    int valido = 0;
    int tamanho;
    char* preco = (char*)malloc(21 * sizeof(char)); // 20 caracteres + 1 para '\0'
    do {
        capturarPreco(preco); // Função já existente para capturar a entrada do usuário
        tamanho = strlen(preco);
        if (tamanho == 0) {
            printf("Preço inválido. Por favor, insira um valor correto.\n");
            continue; 
        }
        if (!validaPreco(preco)) {
            printf("Preço inválido. Tente novamente.\n");
        } else {
            valido = 1;
        }
    } while (!valido);
    return preco;
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