#ifndef EQUI_MODEL_H
#define EQUI_MODEL_H

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

typedef struct EquipamentoNo{
    Equipamento equipamento;
    struct EquipamentoNo* proximo;
 } EquipamentoNo;


int salvarEquipamento(Equipamento*);
Equipamento* carregarEquipamentos(int);
void alteraEquipamento(Equipamento*, int);
int deletarEquipamento(Equipamento*);
int regravaEquipamento(Equipamento*);
int geraIDEqui(void);

#endif
