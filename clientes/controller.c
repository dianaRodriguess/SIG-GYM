#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "model.h"
#include "../view/entradas.h"


void cadastrarCliente(void) {
    Cliente cliente;

    menuCadastrarCliente();
    capturarNome(cliente.nome);
    capturarCPF(cliente.cpf);
    capturarTelefone(cliente.telefone);
    capturarEmail(cliente.email);
    capturarDataNasc(cliente.dataNasc);
    capturarSexo(&cliente.sexo);
    capturarPlano(&cliente.plano);

    printf("|_____________________________________________|\n");
}

void pesquisarCliente(void) {
    Cliente cliente;

    menuPesquisarCliente();
    capturarCPF(cliente.cpf);

    printf("|_____________________________________________|\n");
}

void atualizarCliente(void) {
    Cliente cliente;

    menuAtualizarCliente();
    capturarCPF(cliente.cpf);

    printf("|_____________________________________________|\n");
}

void deletarCliente(void) {
    Cliente cliente;
    
    menuDeletarCliente();
    capturarCPF(cliente.cpf);

    printf("|_____________________________________________|\n");
}
