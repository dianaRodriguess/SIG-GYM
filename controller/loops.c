#include <stdio.h>
#include "loops.h"
#include "../view/entradas.h"
#include "../clientes/controller.h"
#include "../equipamentos/controller.h"
#include "../funcionarios/controller.h"
#include "../treinos/controller.h"
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

        if (opSub == '0') return;

        processarOpcao(opSub, telaVerClientes, telaVerTreinos, telaVerFuncionarios, telaVerEquipamentos);

    } while (opSub != 0);
}