#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "../libs/entradas.h"

// salva o funcionário no arquivo
int salvarFuncionario(Funcionario* funcionario){
    FILE* arquivo = fopen("funcionarios.dat", "ab");
    if(arquivo == NULL){
         return 0;
    }
    if(fwrite(funcionario, sizeof(funcionario), 1, arquivo) != 1){
        return -1;
    }
    fclose(arquivo);
    return 1;
}

// ler o arquivo de funcionários
Funcionario* carregarFuncionarios(char* cpf){
    Funcionario* funcionario = (Funcionario*)malloc(sizeof(Funcionario));
    FILE* arquivo = fopen("funcionarios.dat", "rb");
    if(arquivo == NULL) {
        return NULL;
    }

    while(fread(funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (!strcmp(funcionario->cpf, cpf)) {
            fclose(arquivo);
            return funcionario;
        }
    }
    fclose(arquivo);
    free(funcionario);
    return NULL;
}


// atualiza o status do funcionário no arquivo
int atualizarStatusFun(){

    // return TRUE;
}


// atualiza os dados do funcionário no arquivo
int atualizarDadosFun(){

    // return TRUE;
}
