#ifndef VALIDACOES_H
#define VALIDACOES_H

typedef struct{
   int dia;
   int mes;
   int ano;
} DataAtual;

int validaTelefone   (char*);
int validaCpf(char*);
int verificaDigito(char*, int);
int veriNumIguais(char*, int);
DataAtual obterDataAtual(void);
int anoBissexsto(int);
int validaData(int, int, int);
int validaQuantidade(char*);
int validaName(char*, int);
int validaEmail(char*);
int checaPreco(char*);
int validaPreco(char*);
int verificaCargo(const int);
int verificaPlano(const int);

#endif