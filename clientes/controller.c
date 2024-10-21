#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "../view/entradas.h"


void cadastrarCliente(void) {
    char nome[55], cpf[15], endereco[55], telefone[15], email[55], dataNasc[11];
    char sexo, plano;

    menuCadastrarCliente();
    capturarNome(nome);
    capturarCPF(cpf);
    capturarEndereco(endereco);
    capturarTelefone(telefone);
    capturarEmail(email);
    capturarDataNasc(dataNasc);
    capturarSexo(&sexo);
    capturarPlano(&plano);

    printf("|_____________________________________________|\n");

}

void pesquisarCliente(void) {
    menuPesquisarCliente();
}

void atualizarCliente(void) {
    menuAtualizarCliente();
}

void deletarCliente(void) {
    menuDeletarCliente();
}
