#ifndef _FUN_MODEL_H
#define _FUN_MODEL_H

typedef enum {
    Gerente = 1,
    Professor,
    ASG,
    Atendente
} Cargo;

typedef struct {
    char cpf[15];
    char nome[55];
    Cargo cargo;
    char email[55];
    char telefone[15];
    char dataNasc[11];
    int status;
} Funcionario; 

int salvarFuncionario(Funcionario* funcionario);
Funcionario* carregarFuncionarios(char* cpf);

#endif
