#include <stdio.h>
#include "view/interface.h"
#include "model/cliente.h"

void limparBuffer(void){
    int buffer;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}

int main(void){
    telaPrincipal();
    limparBuffer();
    telaCadastro();
    limparBuffer();
    cadastrarCliente();
    limparBuffer();
    telaPesquisar();
    limparBuffer();
    pesquisarCliente();
    limparBuffer();
    telaAtualizar();
    limparBuffer();
    atualizarCliente();
    limparBuffer();
    telaDeletar();
    limparBuffer();
    deletarCliente();
    limparBuffer();
    telaRelatorios();
    limparBuffer();
    telaInfo();
    limparBuffer();

    return 0;
}