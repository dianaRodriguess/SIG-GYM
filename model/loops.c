#include "../view/interface.h"
#include "../controller/entradas.h"
#include "cliente.h"
#include "equipamentos.h"
#include "funcionario.h"
#include "treino.h"
#include "loops.h"


void loopCadastro(void){
    char opSub;

    do {
        telaCadastro();
        opSub = lerOpcao();
        
        switch (opSub) {
            case '1':
                cadastrarCliente();
                pausarTela();
                break;
            case '2':
                cadastrarTreino();
                pausarTela();
                break;
            case '3':
                cadastrarEquipamento();
                pausarTela();
                break;
            case '4':
                cadastrarFuncionario();
                pausarTela();
                break;
            case '0':
                return;
            }
    } while (opSub != 0);
}