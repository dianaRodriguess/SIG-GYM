#include <stdio.h>
#include <stdlib.h>

void capturarNome(char *nome){
    printf("> Nome: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
}