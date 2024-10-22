#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "../view/entradas.h"

void cadastrarEquipamento(void){
    char nome[55], funcao[27], marca[27], preco[9];
    char quantidade[9], codBarras[13];

    menuCadastrarEquipamento();

    capturarNome(nome);
    capturarFuncao(funcao);
    capturarMarca(marca);
    capturarPreco(preco);
    capturarInt(quantidade);
    capturarCodBarras(codBarras);

    printf("|________________________________________________|\n");
}

void pesquisarEquipamento(void){
    char codBarras[13];

    menuPesquisarEquipamento();

    capturarCodBarras(codBarras);

    printf("|________________________________________________|\n");
}

void atualizarEquipamento(void){
    char codBarras[13];

    menuAtualizarEquipamento();

    capturarCodBarras(codBarras);

    printf("|________________________________________________|\n");
}

void deletarEquipamento(void){
    char codBarras[13];

    menuDeletarEquipamento();

    capturarCodBarras(codBarras);

    printf("|________________________________________________|\n");
}