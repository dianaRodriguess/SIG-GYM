#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "../view/entradas.h"


void cadastrarFuncionario(void) {
    char nome [55], cpf [15], endereco [55], telefone [15], email [55], dataNasc [11];
    char cargo [22];

    menuCadastrarFuncionario();
    capturarNome(nome);
    capturarCPF(cpf);
    capturarEndereco(endereco);
    capturarTelefone(telefone);
    capturarEmail(email);
    capturarDataNasc(dataNasc);
    capturarCargo(cargo);

    printf("|_____________________________________________|\n");
}

void pesquisarFuncionario(void) {

}

void atualizarFuncionario(void) {

}

void deletarFuncionario(void) {

}
