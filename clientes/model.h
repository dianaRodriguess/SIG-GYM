#ifndef MODEL_H
#define MODEL_H

typedef struct {
    char nome[61];
    char cpf[15];
    char telefone[12];
    char email[55];
    char dataNasc[11];
    char sexo;
    char plano;
    int status;
} Cliente;

int salvarCliente(Cliente*);
Cliente* carregarClientes(char*);
int regravaCliente(Cliente*);
int excluirCliente(Cliente*, char*);

#endif