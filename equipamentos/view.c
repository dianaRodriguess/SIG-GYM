#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "../libs/utils.h"


char menuEqui(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                 Equipamentos               |\n");
    printf("----------------------------------------------\n");
    printf("|             1 - Cadastre - se              |\n");
    printf("|             2 - Exibir Dados               |\n");
    printf("|             3 - Alterar Dados              |\n");
    printf("|             4 - Excluir Equipamento        |\n");
    printf("|             0 - Retornar ao Menu Principal |\n");
    printf("----------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

void cadastrarEqui(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|           Cadastro de Equipamento          |\n");
    printf("----------------------------------------------\n");
}

void exibirDados(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                 Exibir Dados               |\n");
    printf("----------------------------------------------\n");
}

void alterarDados(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|                 Alterar Dados              |\n");
    printf("----------------------------------------------\n");
}

void excluiEquipamento(void){
    limparTela();
    printf("----------------------------------------------\n");
    printf("|              Excluir Equipamento           |\n");
    printf("----------------------------------------------\n");
}

void numDados(void) {
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | 1 - %-27s | 2 - %-18s | 3 - %-12s | 4 - %-7s |\n", "ID", "Nome", "Marca", "Qtd.", "Preço");
    printf("----------------------------------------------------------------------------------------------------\n");
}

void dadosEquipamentos(Equipamento* equipamento){
    limparTela();
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| ID: %d \n", equipamento->ID);
    printf("| Nome: %s \n", equipamento->nome);
    printf("| Marca: %s \n", equipamento->marca);
    printf("| Quantidade: %d\n", equipamento->quantidade);
    printf("| Preço: %.2f \n", equipamento->preco);
    printf("----------------------------------------------------------------------------------------------------\n");
}