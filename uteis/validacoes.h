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
int valida_data(int, int, int);
int valida_quantidade(char*);
int valida_name(char*, int);
int valida_email(char*);
int valida_preco(char*);

#endif