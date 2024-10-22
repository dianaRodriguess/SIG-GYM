#include <stdio.h>
#include <stdlib.h>
#include "../view/interface.h"
#include "../clientes/controller.h"
#include "../equipamentos/controller.h"
#include "../model/funcionario.h"
#include "../model/treino.h"
#include "../view/entradas.h"
#include "loops.h"

void menu(void){
        char opMain;
    do{

        telaPrincipal();
        opMain = lerOpcaoMain();

        switch (opMain){
            case '1':
                loopCadastrar();
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