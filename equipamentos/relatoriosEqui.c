#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modelEqui.h"
#include "../libs/utils.h"

void listarEquipamentosAtivos(void) {
    FILE* arquivo = fopen("equipamentos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Equipamento equipamento;
    int encontrados = 0;

    limparTela();
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-30s | %-25s | %-15s | %-10s |\n", "ID", "Nome", "Marca", "Qtd.", "Preço");
    printf("----------------------------------------------------------------------------------------------------\n");

    while (fread(&equipamento, sizeof(Equipamento), 1, arquivo)) {
        if (equipamento.status == 1) {
            printf("| %-5d | %-30s | %-25s | %-15d | R$ %-8.2f |\n", 
                   equipamento.ID, equipamento.nome, equipamento.marca, 
                   equipamento.quantidade, equipamento.preco);
            encontrados = 1;
        }
    }
    
    if (!encontrados) {
        printf("|                               Nenhum equipamento ativo encontrado.                               |\n");
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}


void listarEquipamentosInativos(void) {
    FILE* arquivo = fopen("equipamentos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Equipamento equipamento;
    int encontrados = 0;

    limparTela();
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-30s | %-25s | %-15s | %-10s |\n", "ID", "Nome", "Marca", "Qtd.", "Preço");
    printf("----------------------------------------------------------------------------------------------------\n");

    while (fread(&equipamento, sizeof(Equipamento), 1, arquivo)) {
        if (equipamento.status == 0) {
            printf("| %-5d | %-30s | %-25s | %-15d | R$ %-8.2f |\n", 
                   equipamento.ID, equipamento.nome, equipamento.marca, 
                   equipamento.quantidade, equipamento.preco);
            encontrados = 1;
        }
    }
    
    if (!encontrados) {
        printf("|                              Nenhum equipamento inativo encontrado.                              |\n");
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void allEquipamentos(void) {
    FILE* arquivo = fopen("equipamentos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Equipamento equipamento;
    int encontrados = 0;

    limparTela();
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-30s | %-25s | %-15s | %-10s |\n", "ID", "Nome", "Marca", "Qtd.", "Preço");
    printf("----------------------------------------------------------------------------------------------------\n");

    while (fread(&equipamento, sizeof(Equipamento), 1, arquivo)) {
        
        printf("| %-5d | %-30s | %-25s | %-15d | R$ %-8.2f |\n", 
                equipamento.ID, equipamento.nome, equipamento.marca, 
                equipamento.quantidade, equipamento.preco);
        encontrados = 1;
        
    }
    
    if (!encontrados) {
        printf("|                              Nenhum equipamento inativo encontrado.                              |\n");
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    fclose(arquivo);
}

void allEquipamentosOrdenado(void) {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                             Equipamentos (Ordenados por Nome)                                          |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-5s | %-30s | %-25s | %-15s | %-10s   |\n", "ID", "Nome", "Marca", "Qtd.", "Preço");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");

    FILE* arquivo = fopen("equipamentos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    // Cria a lista encadeada
    EquipamentoNo* lista = NULL;
    Equipamento equipamento;

    while (fread(&equipamento, sizeof(Equipamento), 1, arquivo)) {
        EquipamentoNo* novo = (EquipamentoNo*)malloc(sizeof(EquipamentoNo));
        if (novo == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
            return;
        }
        novo->equipamento = equipamento; // Copia o exercício para o novo nó
        novo->proximo = lista;
        lista = novo;
    }
    fclose(arquivo);

    // Ordena a lista encadeada por nome
    if (lista != NULL) {
        EquipamentoNo* i;
        EquipamentoNo* j;
        for (i = lista; i->proximo != NULL; i = i->proximo) {
            for (j = i->proximo; j != NULL; j = j->proximo) {
                if (strcmp(i->equipamento.nome, j->equipamento.nome) > 0) {
                    Equipamento temp = i->equipamento;
                    i->equipamento = j->equipamento;
                    j->equipamento = temp;
                }
            }
        }
    }

    // Exibe os exercícios
    EquipamentoNo* atual = lista;
    while (atual != NULL) {
        printf("| %-5d | %-30s | %-25s | %-15d | R$ %-8.2f |\n", 
                atual->equipamento.ID, atual->equipamento.nome, atual->equipamento.marca, 
                atual->equipamento.quantidade, atual->equipamento.preco);
        atual = atual->proximo; // Avança para o próximo nó
    }

    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    // Libera a memória
    atual = lista;
    while (atual != NULL) {
        EquipamentoNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
