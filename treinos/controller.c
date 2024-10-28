#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "../view/entradas.h"


void cadastrarTreino(void) {
    char nome [55], musculos [62], repeticao [32], cliente [15];;

    menuCadastrarTreino();
    capturarNome(nome);
    capturarMusculos(musculos);
    capturarRepeticao(repeticao);
    capturarCPF(cliente);

    printf("|_____________________________________________|\n");
}

void pesquisarTreino(void) {

}

void atualizarTreino(void) {

}

void deletarTreino(void) {

}
