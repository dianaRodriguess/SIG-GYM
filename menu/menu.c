#include <stdio.h>
#include <stdlib.h>
#include "libs/utils.h"
#include "clientes/controller.h"
    
char menuPrincipal(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                    SigGym                  |\n");
    printf("----------------------------------------------\n");
    printf("|             1 - Clientes                   |\n");
    printf("|             2 - Treinos                    |\n");
    printf("|             3 - Alterar Dados              |\n");
    printf("|             4 - Excluir Cliente            |\n");
    printf("|             0 - Retornar ao Menu Principal |\n");
    printf("----------------------------------------------\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

void menu(void){
    char opMain;
    do{
        opMain = menuPrincipal();

        switch (opMain){
            case '1':
                menuCliente();
                break;
            case '2':
                loopPesquisar();
                break;

            case '3':
                loopAtualizar();
                break;

            case '4':
                loopDeletar();
                break;

            case '5':
                loopRelatorios();
                break;

            case '6':
                telaInfo();
                pausarTela();
                break;

            case '0':
                printf("Obrigado por usar o programa. :)\n");
                opMain = '0';
                break;

            default:
                printf("Opção inválida!\n");
                pausarTela();
                break;
        }

    } while (opMain != '0');
}