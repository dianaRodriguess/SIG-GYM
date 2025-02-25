#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../libs/utils.h"
#include "../libs/leitura_dados.h"
#include "viewEqui.h"
#include "../libs/entradas.h"

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

Equipamento* carregarEquipamentos(int id){
    Equipamento* equipamento = (Equipamento*)malloc(sizeof(Equipamento));
    FILE* arquivo = fopen("equipamentos.dat", "rb");
    if(arquivo == NULL) {
        return NULL;
    }

    while(fread(equipamento, sizeof(Equipamento), 1, arquivo)) {
        if(equipamento->ID == id){
            fclose(arquivo);
            return equipamento;
        }
    }
    fclose(arquivo);
    free(equipamento);
    return NULL;
}

void alteraEquipamento(Equipamento* equipamento, int op){
    float preco;
    int opcao;
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
            opcao = leQuantidade();
            equipamento->quantidade = opcao;
            break;
        case 4:
            limparBuffer();
            preco = lePreco();  
            equipamento->preco = preco;
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    regravaEquipamento(equipamento);
    dadosEquipamentos(equipamento);
    if(entrada != NULL){
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
        if (novoEquipamento->ID == equipamento->ID){
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
    free(novoEquipamento);
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

int geraIDEqui(void) {
    Equipamento eq;
    FILE* file = fopen("equipamentos.dat", "rb");

    if (file == NULL) return 1; // Se o arquivo não existe, começamos do ID 1

    fseek(file, -sizeof(Equipamento), SEEK_END); // Move para o último registro
    fread(&eq, sizeof(Equipamento), 1, file); // Lê o último registro
    fclose(file);

    return eq.ID + 1; // Retorna o próximo ID válido
}
