#include <stdio.h>
#include "view/interface.c"
#include "model/cliente.c"

int main(void){
    telaPrincipal();
    telaCadastro();
    cadastrarCliente();
    telaPesquisar();
    pesquisarCliente();
    telaAtualizar();
    atualizarCliente();
    telaDeletar();
    deletarCliente();
    telaRelatorios();
    telaInfo();

    return 0;
}