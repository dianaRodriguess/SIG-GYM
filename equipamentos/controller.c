#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "../view/entradas.h"

void mostrarEquipamentos(Equipamento* equi){
    
    printf("\n... INFORMAÇÕES DO EQUIPAMENTO ...\n");

    printf(">> Nome: %s\n", equi->nome);
    printf(">> Marca: %s\n", equi->marca);
    printf(">> Funcao: %s\n", equi->funcao);
    printf(">> Preco: %.2f\n", equi->preco);
    printf(">> Quantidade: %d\n", equi->quantidade);
    printf(">> Codigo de Barras: %d\n", equi->codBarras);
    printf(">> Status: %d\n", equi->status);
    printf("|________________________________________________|\n");
}

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
    equi->status = 1;

    escreverNoArquivoEqui(equi);
    free(equi);
}

void pesquisarEquipamento(void){
    Equipamento* equi = malloc(sizeof(Equipamento));

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