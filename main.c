#include <stdio.h>
#include <stdlib.h>
#include "view/interface.h"
#include "model/cliente.h"
#include "model/equipamentos.h"
#include "model/funcionario.h"
#include "model/treino.h"
#include "controller/entradas.h"


int main(void){
    char opMain, opSub;

    do{

        telaPrincipal();
        opMain = lerOpcao();

        switch (opMain){
            case '1':
                telaCadastro();
                pausarTela();
                break;
            case '2':
                telaPesquisar();
                pausarTela();
                break;
            case '3':
                telaAtualizar();
                pausarTela();
                break;
            case '4':
                telaDeletar();
                pausarTela();
                break;
            case '5':
                telaRelatorios();
                pausarTela();
                break;
            case '6':
                telaInfo();
                pausarTela();
                break;
            default:
                printf("Opção inválida!\n");
                pausarTela();
                break;
        }

    } while (opMain != '0');
    


    //printf("A seguir telas de menu. Clique <ENTER> para prosseguir: \n");
    //limparBuffer();
    //telaPrincipal();
    //limparBuffer();
    //telaCadastro();
    //limparBuffer();
    //telaPesquisar();
    //limparBuffer();
    //telaAtualizar();
    //limparBuffer();
    //telaDeletar();
    //limparBuffer();
    //telaRelatorios();
    //limparBuffer();
    //telaInfo();
    //limparBuffer();

    //system("clear");
    //printf("A seguir telas do modulo cliente. Clique <ENTER> para prosseguir: \n");
    //limparBuffer();
    //cadastrarCliente();
    //limparBuffer();
    //pesquisarCliente();
    //limparBuffer();
    //atualizarCliente();
    //limparBuffer();
    //deletarCliente();
    //limparBuffer();
//
    //system("clear");
    //printf("A seguir telas do modulo treino. Clique <ENTER> para prosseguir: \n");
    //limparBuffer();
    //cadastrarTreino();
    //limparBuffer();
    //pesquisarTreino();
    //limparBuffer();
    //atualizarTreino();
    //limparBuffer();
    //deletarTreino();
    //limparBuffer();
//
    //system("clear");
    //printf("A seguir telas do modulo funcionário. Clique <ENTER> para prosseguir: \n");
    //limparBuffer();
    //cadastrarFuncionario();
    //limparBuffer();
    //pesquisarFuncionario();
    //limparBuffer();
    //atualizarFuncionario();
    //limparBuffer();
    //deletarFuncionario();
    //limparBuffer();
//
    //system("clear");
    //printf("A seguir telas do modulo equipamentos. Clique <ENTER> para prosseguir: \n");
    //limparBuffer();
    //cadastrarEquipamento();
    //limparBuffer();
    //pesquisarEquipamento();
    //limparBuffer();
    //atualizarEquipamento();
    //limparBuffer();
    //deletarEquipamento();
    //limparBuffer();

    return 0;
}