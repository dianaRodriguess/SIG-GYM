#ifndef MODEL_H
#define MODEL_H

typedef struct {
    char nome[61];
    char cpf[15];
    char telefone[12];
    char email[55];
    char dataNasc[11];
    Sexo sexo;
    Plano plano;
    Status status;
} Cliente;

typedef enum {
    Masculino = 1,
    Feminino = 2
} Sexo;

typedef enum {
    Básico = 1,
    Intermediário = 2,
    Avançado = 3
} Plano;

typedef enum {
    Ativo = 1,
    Inativo = 0
} Status;

int salvarCliente(Cliente*);
Cliente* carregarClientes(char*);
int regravaCliente(Cliente*);
int excluirCliente(Cliente*, char*);
void alteraCliente(Cliente*, int);

#endif