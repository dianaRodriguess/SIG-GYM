#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "../libs/utils.h"



char menuCentralEquipamentos(void){
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

void cadastrarEquipamento(void){
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
    limparTela();
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("|                                           Alterar Dados                                       |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| 1 - Nome | 2 - Marca | 3 - Função | 4 - Código de Barras | 5 - Quantidade | 6 - Status | 7 - Preço |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
}

void dadosEquipamentos(Equipamento* equipamento){
    limparTela();
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| Nome: %s \n", equipamento->nome);
    printf("| Marca: %s \n", equipamento->marca);
    printf("| Função: %s \n", equipamento->funcao);
    printf("| Código de Barras: %d \n", equipamento->id);
    printf("| Quantidade: %d\n", equipamento->quantidade);
    printf("| Status: %d \n", equipamento->status);
    printf("| Preço: %f \n", equipamento->preco);
    printf("----------------------------------------------------------------------------------------------------\n");
}
