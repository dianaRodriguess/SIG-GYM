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
    printf("|             3 - Exercícios                 |\n");
    printf("|             4 - Equipamentos               |\n");
    printf("|             5 - Funcionários               |\n");
    printf("|             6 - Equipe                     |\n");
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
                menuEquipe();
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

void menuEquipe(void){
    limparTela();
    char opcao;
    printf("---------------------------------------------\n");
    printf("|                 Colaboradores             |\n");
    printf("---------------------------------------------\n");
    printf("|           > André Leandro                 |\n");
    printf("|           > GitHub: andrewszada           |\n");
    printf("|           > Paulo Douglas                 |\n");
    printf("|           > GitHub: Paulo-Douglas         |\n");
    printf("|           > Anderson Gabriel              |\n");
    printf("|           > GitHub: anderson-cruz13       |\n");
    printf("|           > Diana Rodrigues               |\n");
    printf("|           > GitHub: dianaRodriguess       |\n");
    printf("----------------------------------------------\n");

}