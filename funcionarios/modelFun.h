#ifndef FUN_MODEL_H
#define FUN_MODEL_H

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

int salvarFuncionario(Funcionario*);
Funcionario* carregarFuncionarios(char*);
int regravaFuncionario(Funcionario*);
int deletarFuncionario(Funcionario*);
int checaCPFun(char* cpf);
void alteraFuncionario(Funcionario*, int);

#endif
