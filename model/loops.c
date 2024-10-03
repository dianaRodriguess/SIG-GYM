#include "../view/interface.h"
#include "../controller/entradas.h"
#include "cliente.h"
#include "equipamentos.h"
#include "funcionario.h"
#include "treino.h"
#include "loops.h"


char opSub;


void loopCadastro(void){
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
                cadastrarFuncionario();
                pausarTela();
                break;
            case '4':
                cadastrarEquipamento();
                pausarTela();
                break;
            case '0':
                return;
            }
    } while (opSub != 0);
}


void loopPesquisa(void){
    do {
        telaCadastro();
        opSub = lerOpcao();
        
        switch (opSub) {
            case '1':
                pesquisarCliente();
                pausarTela();
                break;
            case '2':
                pesquisarTreino();
                pausarTela();
                break;
            case '3':
                pesquisarFuncionario();
                pausarTela();
                break;
            case '4':
                pesquisarEquipamento();
                pausarTela();
                break;
            case '0':
                return;
            }
    } while (opSub != 0);
}