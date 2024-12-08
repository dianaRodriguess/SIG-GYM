#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "../view/entradas.h"

void cadastrarEquipamento(void){
    Equipamento* equi = malloc(sizeof(Equipamento));
    if (equi == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    menuCadastrarEquipamento();

    capturarNome(equi->nome);
    capturarFuncao(equi->funcao);
    capturarMarca(equi->marca);
    capturarPreco(&(equi->preco));
    capturarQuantidade(&(equi->quantidade));
    capturarCodBarras(&(equi->codBarras));
    printf("|________________________________________________|\n");
    escreverNoArquivoEqui(equi);
    equi->status = 1;
}

void pesquisarEquipamento(void){
    Equipamento* equi = malloc(sizeof(Equipamento));
    // char codBarras[13];

    menuPesquisarEquipamento();

    capturarCodBarras(&(equi->codBarras));

    printf("|________________________________________________|\n");
    free(equi);
}

void atualizarEquipamento(void){
    Equipamento* equi = malloc(sizeof(Equipamento));
    // char codBarras[13];

    menuAtualizarEquipamento();

    capturarCodBarras(&(equi->codBarras));

    printf("|________________________________________________|\n");
    free(equi);
}

void deletarEquipamento(void){
    Equipamento* equi = malloc(sizeof(Equipamento));
    // char codBarras[13];

    menuDeletarEquipamento();

    capturarCodBarras(&(equi->codBarras));

    printf("|________________________________________________|\n");
    free(equi);
}