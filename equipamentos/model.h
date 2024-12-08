#ifndef _EQUI_MODEL_H
#define _EQUI_MODEL_H

#define FALSE 0
#define TRUE 1

typedef struct {
    char nome[55]; 
    char marca[27];
    char funcao[27];
    int codBarras[13];
    int quantidade[9]; 
    float preco[9];
    char status;
} Equipamento;

#endif
