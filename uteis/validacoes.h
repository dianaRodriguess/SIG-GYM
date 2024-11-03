#ifndef VALIDACOES_H
#define VALIDACOES_H

typedef struct{
   int dia;
   int mes;
   int ano;
} DataAtual;

int valida_telefone(char*);
int valida_cpf(char*);
int verifica_digito(char*, int);
int veri_num_iguais(char*, int);
int ano_bissexto(int);

#endif