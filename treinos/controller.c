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
    char CodTreino[6];

    menuPesquisarTreino();
    capturarCodTreino(CodTreino);

    printf("|_____________________________________________|\n");
}

void atualizarTreino(void) {
    char CodTreino[6];

    menuAtualizarTreino();
    capturarCPF(CodTreino);

    printf("|_____________________________________________|\n");
}

void deletarTreino(void) {
    char CodTreino[6];
    
    menuDeletarTreino();
    capturarCPF(CodTreino);

    printf("|_____________________________________________|\n");
}
