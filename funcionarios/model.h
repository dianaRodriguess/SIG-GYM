#ifndef _FUN_MODEL_H
#define _FUN_MODEL_H

#define FALSE 0
#define TRUE 1

typedef struct {
    char cpf[15];
    char nome[55];
    char cargo[22];
    char email[55];
    char telefone[15];
    char dataNasc[11];
    char status;
} Funcionario; 

#endif
