#ifndef _EQUI_MODEL_H
#define _EQUI_MODEL_H

#define FALSE 0
#define TRUE 1

typedef struct {
    char nome[55]; 
    char marca[27];
    char funcao[27]; 
    int codBarras;
    int quantidade; 
    int status; // 1 = ativo, 0 = passivo
    float preco;
} Equipamento;

int salvarEquipamento(Equipamento* equipamento);
Equipamento* carregarEquipamentos(char* codBarras);
void alteraEquipamento(Equipamento* equipamento, int op);
int deletarEquipamento(Equipamento* equipamento);
int regravaEquipamento(Equipamento* equipamento);
int excluirClientes(Equipamento* equipamento, char *codBarras);

#endif
