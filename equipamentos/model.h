#ifndef _EQUI_MODEL_H
#define _EQUI_MODEL_H

#define FALSE 0
#define TRUE 1

typedef struct {
    int ID;
    char nome[55]; 
    char marca[27];
    int quantidade; 
    float preco;
    int status;
} Equipamento;

int salvarEquipamento(Equipamento* equipamento);
Equipamento* carregarEquipamentos(char* codBarras);
void alteraEquipamento(Equipamento* equipamento, int op);
int deletarEquipamento(Equipamento* equipamento);
int regravaEquipamento(Equipamento* equipamento);
int excluirClientes(Equipamento* equipamento, char *codBarras);
int geraID(void);

#endif
