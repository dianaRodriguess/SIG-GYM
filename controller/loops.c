#include <stdio.h>
#include "entradas.h"
#include "loops.h"
#include "../model/cliente.h"
#include "../model/equipamentos.h"
#include "../model/funcionario.h"
#include "../model/treino.h"
#include "../view/interface.h"


char opSub;


void processarOpcao(char opcao,
                    void (*operacaoCliente)(),
                    void (*operacaoTreino)(),
                    void (*operacaoFuncionario)(),
                    void (*operacaoEquipamento)()
                    ){

    switch (opcao) {
        case '1':
            operacaoCliente();
            break;
        case '2':
            operacaoTreino();
            break;
        case '3':
            operacaoFuncionario();
            break;
        case '4':
            operacaoEquipamento();
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    pausarTela();

}


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
            default:
                printf("Opção inválida!\n");
                pausarTela();
                break;
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
            default:
                printf("Opção inválida!.\n");
                pausarTela();
                break;
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
            default:
                printf("Opção inválida!.\n");
                pausarTela();
                break;
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
            default:
                printf("Opção inválida!.\n");
                pausarTela();
                break;
            }
    } while (opSub != 0);
}


void loopRelatorios(void){
    do {
        telaRelatorios();
        opSub = lerOpcao();
        
        switch (opSub) {
            case '1':
                printf(">>>> Ver todos os clientes. Tecle <0> para sair.\n");
                pausarTela();
                break;
            case '2':
                printf(">>>> Ver todos os treinos. Tecle <0> para sair.\n");
                pausarTela();
                break;
            case '3':
                printf(">>>> Ver todos os funcionários. Tecle <0> para sair.\n");
                pausarTela();
                break;
            case '4':
                printf(">>>> Ver todos os equipamnetos. Tecle <0> para sair.\n");
                pausarTela();
                break;
            case '0':
                return;
            default:
                printf("Opção inválida!.\n");
                pausarTela();
                break;
            }
    } while (opSub != 0);
}