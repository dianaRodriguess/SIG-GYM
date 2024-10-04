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
    pausarSubTela();
}


void loopCadastrar(void){
    do {
        telaCadastro();
        opSub = lerOpcao();

        if (opSub == '0') return;

        processarOpcao(opSub, cadastrarCliente, cadastrarTreino, 
                        cadastrarFuncionario, cadastrarEquipamento);

    } while (opSub != 0);
}


void loopPesquisar(void){
    do {
        telaPesquisar();
        opSub = lerOpcao();

        if (opSub == '0') return;

        processarOpcao(opSub, pesquisarCliente, pesquisarTreino,
                        pesquisarFuncionario, pesquisarEquipamento);

    } while (opSub != 0);
}


void loopAtualizar(void){
    do {
        telaAtualizar();
        opSub = lerOpcao();

        if (opSub == '0') return;

        processarOpcao(opSub, atualizarCliente, atualizarTreino,
                        atualizarFuncionario, atualizarEquipamento);

    } while (opSub != 0);
}


void loopDeletar(void){
    do {
        telaDeletar();
        opSub = lerOpcao();

        if (opSub == '0') return;

        processarOpcao(opSub, deletarCliente, deletarTreino, deletarFuncionario,
                        deletarEquipamento);

    } while (opSub != 0);
}


void loopRelatorios(void){
    do {
        telaRelatorios();
        opSub = lerOpcao();
        
        switch (opSub) {
            case '1':
                printf(">>>> Ver todos os clientes.\n");
                pausarSubTela();
                break;
            case '2':
                printf(">>>> Ver todos os treinos.\n");
                pausarSubTela();
                break;
            case '3':
                printf(">>>> Ver todos os funcionários.\n");
                pausarSubTela();
                break;
            case '4':
                printf(">>>> Ver todos os equipamnetos.\n");
                pausarSubTela();
                break;
            case '0':
                return;
            default:
                printf("Opção inválida!.\n");
                pausarSubTela();
                break;
            }
    } while (opSub != 0);
}