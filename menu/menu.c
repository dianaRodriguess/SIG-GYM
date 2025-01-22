#include <stdio.h>
#include <stdlib.h>
#include "../libs/utils.h"
#include "../clientes/controllerCli.h"
#include "../equipamentos/controllerEqui.h"
#include "../funcionarios/controllerFun.h"
    
char menuPrincipal(void){
    limparTela();
    char opcao;
    printf("----------------------------------------------\n");
    printf("|                    SigGym                  |\n");
    printf("----------------------------------------------\n");
    printf("|             1 - Clientes                   |\n");
    printf("|             2 - Treinos                    |\n");
    printf("|             3 - Exercícios                 |\n");
    printf("|             4 - Equipamentos               |\n");
    printf("|             5 - Funcionários               |\n");
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
            case '4':
                menuEquipamentos();
                break;
            case '5':
                menuFuncionario();
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