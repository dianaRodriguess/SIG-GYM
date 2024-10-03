#include <stdio.h>
#include "../view/interface.h"
#include "../controller/entradas.h"
#include "cliente.h"
#include "equipamentos.h"
#include "funcionario.h"
#include "treino.h"
#include "loops.h"


char opSub;


void loopCadastrar(void){
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


void loopPesquisar(void){
    do {
        telaPesquisar();
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


void loopAtualizar(void){
    do {
        telaAtualizar();
        opSub = lerOpcao();
        
        switch (opSub) {
            case '1':
                atualizarCliente();
                pausarTela();
                break;
            case '2':
                atualizarTreino();
                pausarTela();
                break;
            case '3':
                atualizarFuncionario();
                pausarTela();
                break;
            case '4':
                atualizarEquipamento();
                pausarTela();
                break;
            case '0':
                return;
            }
    } while (opSub != 0);
}


void loopDeletar(void){
    do {
        telaDeletar();
        opSub = lerOpcao();
        
        switch (opSub) {
            case '1':
                deletarCliente();
                pausarTela();
                break;
            case '2':
                deletarTreino();
                pausarTela();
                break;
            case '3':
                deletarFuncionario();
                pausarTela();
                break;
            case '4':
                deletarEquipamento();
                pausarTela();
                break;
            case '0':
                return;
            }
    } while (opSub != 0);
}


void loopRelatorios(void){
    do {
        telaRelatorios();
        opSub = lerOpcao();
        
        switch (opSub) {
            case '1':
                printf(">>>> Ver todos os clientes");
                pausarTela();
                break;
            case '2':
                printf(">>>> Ver todos os treinos");
                pausarTela();
                break;
            case '3':
                printf(">>>> Ver todos os funcionários");
                pausarTela();
                break;
            case '4':
                printf(">>>> Ver todos os equipamnetos");
                pausarTela();
                break;
            case '0':
                return;
            }
    } while (opSub != 0);
}