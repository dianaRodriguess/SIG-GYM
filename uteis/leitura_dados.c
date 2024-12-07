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
