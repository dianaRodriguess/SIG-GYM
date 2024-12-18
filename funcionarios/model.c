#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "../libs/entradas.h"
#include "../libs/utils.h"

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

// atualiza os dados do funcionário no arquivo
int regravaFuncionario(Funcionario* funcionario){
    FILE* arquivo = fopen("funcinarios.dat", "r+b");
    if(arquivo == NULL){
        return 0; 
    }

    Funcionario* novofuncionario = (Funcionario*)malloc(sizeof(Funcionario));
    while (fread(novofuncionario, sizeof(Funcionario), 1, arquivo)) {
        if (!strcmp(novofuncionario->cpf, funcionario->cpf)) {
            fseek(arquivo, -sizeof(Funcionario), SEEK_CUR);
            if(fwrite(funcionario, sizeof(Funcionario), 1, arquivo)){
                fclose(arquivo);
                free(novofuncionario);
                return 1; 
            }
            fclose(arquivo);
            free(novofuncionario);
            return -1; 
        }
    }
    fclose(arquivo);
    free(novofuncionario);
    return -2; 
}

// muda o status do funcionário
int deletarFuncionario(Funcionario* funcionario){
    if(funcionario->status == 1){
        funcionario->status = 0;
        regravaCliente(funcionario);
        return 1;
    } else {
        return -1;
    }
    
    return -2;
}

int checaCPF(char* cpf){
    char op;
    Funcionario* funcionario = carregarFuncionario(cpf);

    if(funcionario != NULL){
        if(funcionario->status == 0){
            op = confirmação("funcionario", "você possui uma conta inativa no nosso sistema. Deseja reativá-la?");
            switch(op) {
            case '1':
                funcionario->status = 1;
                regravaCliente(funcionario);
                free(funcionario);
                return 1;
            case '0':
                free(funcionario);
                return 0;
            default:
                printf("Opção inválida\n");
                break;
            }
        } else if (funcionario->status == 1){
            return -1;
        }
    } else {
       return 0;
    }

    return -4;
}
