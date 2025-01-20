#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../libs/utils.h"
#include "../libs/leitura_dados.h"
#include "model.h"
#include "../libs/entradas.h"
#include "view.h"


int salvarEquipamento(Equipamento* equipamento){
    FILE* arquivo = fopen("equipamentos.dat", "ab");
    if(arquivo == NULL){
         return 0;
    }
    if(fwrite(equipamento, sizeof(Equipamento), 1, arquivo) != 1){
        return -1;
    }
    fclose(arquivo);
    return 1;
}

Equipamento* carregarEquipamentos(int id) {
    Equipamento* equipamento = (Equipamento*)malloc(sizeof(Equipamento));
    FILE* arquivo = fopen("equipamentos.dat", "rb");
    if (arquivo == NULL) {
        free(equipamento);
        return NULL;
    }

    while (fread(equipamento, sizeof(Equipamento), 1, arquivo)) {
        if (equipamento->id == id) {
            fclose(arquivo);
            return equipamento;
        }
    }
    fclose(arquivo);
    free(equipamento);
    return NULL;
}

void alteraEquipamento(Equipamento* equipamento, int op){
    char* entrada = NULL;

    switch(op){
        case 1:
            limparBuffer();
            entrada = leNome();
            strcpy(equipamento ->nome, entrada);
            break;
        case 2:
            limparBuffer();
            entrada = leMarca();
            strcpy(equipamento->marca, entrada);
            break;
        case 3:
            limparBuffer();
            entrada = leFuncao();
            strcpy(equipamento->funcao, entrada);
            break;
        case 4:
            limparBuffer();
            entrada = leQuantidade();
            equipamento->quantidade = atoi(entrada);
            break;
        case 5:
            limparBuffer();
            entrada = lePreco();  
            equipamento->preco = strtof(entrada, NULL);  // converte a string para float e armazena no campo 'preco'
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    regravaEquipamento(equipamento); 
    dadosEquipamentos(equipamento);
    if (entrada != NULL){
        free(entrada);
    }
    
}

int regravaEquipamento(Equipamento* equipamento){
    FILE* arquivo = fopen("equipamentos.dat", "r+b");
    if(arquivo == NULL){
        return 0;
    
    }
    Equipamento* novoEquipamento = (Equipamento*)malloc(sizeof(Equipamento));
    while (fread(novoEquipamento, sizeof(Equipamento), 1, arquivo)){
        if (novoEquipamento->id == equipamento->id) {
            fseek(arquivo, -sizeof(Equipamento), SEEK_CUR);
            if(fwrite(equipamento, sizeof(Equipamento), 1, arquivo)){
                fclose(arquivo);
                free(novoEquipamento);
                return TRUE;
        }
        fclose(arquivo);
        free(novoEquipamento);
        return -1;
        }
    }
    fclose(arquivo);
    return -2;
}


int excluirClientes(Equipamento* equipamento, char *id){
    FILE* arquivo = fopen("equipamentos.dat", "r+b");
    if(arquivo == NULL){
        return 0;
    }

    while(fread(equipamento, sizeof(Equipamento), 1, arquivo)){
        if((equipamento->id == *id) && equipamento->status == 1){
            fseek(arquivo, -sizeof(Equipamento), SEEK_CUR);
            equipamento->status = 0;
            if(fwrite(equipamento, sizeof(Equipamento), 1, arquivo)){
                fclose(arquivo);
                return TRUE;
            }
            fclose(arquivo);
            return -1;
        }
    }
    fclose(arquivo);
    return -2;
}

int deletarEquipamento(Equipamento* equipamento){
    if(equipamento->status == 1){
        equipamento->status = 0;
        regravaEquipamento(equipamento);
        return 1;
    } else {
        return -1;
    }
    
    return -2;
}

int checaEquipamentoID(int id){
    char op;
    Equipamento* equipamento = carregarEquipamentos(id);

    if(equipamento != NULL){
        if(equipamento->status == 0){
            op = confirmação("cliente", "você possui um equipamento inativo no nosso sistema. Deseja reativá-la?");
            switch(op) {
            case '1':
                equipamento->status = 1;
                regravaEquipamento(equipamento);
                free(equipamento);
                return 1;
            case '0':
                free(equipamento);
                return 0;
            default:
                printf("Opção inválida\n");
                break;
            }
        } else if (equipamento->status == 1){
            return -1;
        }
    } else {
       return 0;
    }

    return -4;
}

