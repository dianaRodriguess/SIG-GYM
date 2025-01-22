#include <stdio.h>
#include <string.h>
#include "../modelEqui.h"
#include "../../libs/utils.h"

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
