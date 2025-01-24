#ifndef MODEL_CLI_H
#define MODEL_CLI_H

typedef enum {
    Masculino = 1,
    Feminino = 2
} Sexo;

typedef enum {
    Basico = 1,
    Intermediario = 2,
    Avancado = 3
} Plano;

typedef enum {
    Ativo = 1,
    Inativo = 0
} Status;

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

typedef struct ClienteNo{
    Cliente cliente;
    struct ClienteNo* proximo;
} ClienteNo;


int salvarCliente(Cliente*);
Cliente* carregarClientes(char*);
int regravaCliente(Cliente*);
int excluirClientes(Cliente*, char*);
void alteraCliente(Cliente*, int);
int deletarCliente(Cliente*);
int checaCPF(char*);

#endif