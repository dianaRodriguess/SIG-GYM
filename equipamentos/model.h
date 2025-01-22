#ifndef _EQUI_MODEL_H
#define _EQUI_MODEL_H

#define FALSE 0
#define TRUE 1

typedef struct {
    int ID;
    char nome[31]; 
    char marca[26];
    int quantidade; 
    float preco;
    int status;
} Equipamento;

int salvarEquipamento(Equipamento*);
Equipamento* carregarEquipamentos(int);
void alteraEquipamento(Equipamento*, int);
int deletarEquipamento(Equipamento* equipamento);
int regravaEquipamento(Equipamento* equipamento);
int geraID(void);

#endif
