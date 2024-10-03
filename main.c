#include <stdio.h>
#include <stdlib.h>
#include "view/interface.h"
#include "model/cliente.h"
#include "model/equipamentos.h"
#include "model/funcionario.h"
#include "model/treino.h"
#include "controller/entradas.h"


int main(void){

    printf("A seguir telas de menu. Clique <ENTER> para prosseguir: \n");
    limparBuffer();
    telaPrincipal();
    limparBuffer();
    telaCadastro();
    limparBuffer();
    telaPesquisar();
    limparBuffer();
    telaAtualizar();
    limparBuffer();
    telaDeletar();
    limparBuffer();
    telaRelatorios();
    limparBuffer();
    telaInfo();
    limparBuffer();

    system("clear");
    printf("A seguir telas do modulo cliente. Clique <ENTER> para prosseguir: \n");
    limparBuffer();
    cadastrarCliente();
    limparBuffer();
    pesquisarCliente();
    limparBuffer();
    atualizarCliente();
    limparBuffer();
    deletarCliente();
    limparBuffer();

    system("clear");
    printf("A seguir telas do modulo treino. Clique <ENTER> para prosseguir: \n");
    limparBuffer();
    cadastrarTreino();
    limparBuffer();
    pesquisarTreino();
    limparBuffer();
    atualizarTreino();
    limparBuffer();
    deletarTreino();
    limparBuffer();

    system("clear");
    printf("A seguir telas do modulo funcionário. Clique <ENTER> para prosseguir: \n");
    limparBuffer();
    cadastrarFuncionario();
    limparBuffer();
    pesquisarFuncionario();
    limparBuffer();
    atualizarFuncionario();
    limparBuffer();
    deletarFuncionario();
    limparBuffer();

    system("clear");
    printf("A seguir telas do modulo equipamentos. Clique <ENTER> para prosseguir: \n");
    limparBuffer();
    cadastrarEquipamento();
    limparBuffer();
    pesquisarEquipamento();
    limparBuffer();
    atualizarEquipamento();
    limparBuffer();
    deletarEquipamento();
    limparBuffer();

    return 0;
}