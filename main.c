#include <stdio.h>
#include <stdlib.h>
#include "view/interface.c"

int main(void){
    int opcao;
    int telaAtual = -1;

    do
    {
        opcao = telaPrincipal();

        if(opcao == 0){
            printf("Saindo...\n");
            break;
        }

        if(opcao >= 1 && opcao < 7){

            int escolha;

            do{

                if(opcao != telaAtual){
                    system("clear");
                    telaAtual = opcao;
                }

                switch (opcao) {
                    case 1:
                        escolha = telaCadastro();
                        break;
                    case 2:
                        escolha = telaPesquisar();
                        break;
                    case 3:
                        escolha = telaAtualizar();
                        break;
                    case 4:
                        escolha = telaDeletar();
                        break;
                    case 5:
                        escolha = telaRelatorios();
                        break;
                    case 6:
                        escolha = telaInfo();
                        break;
                }

            } while (escolha != 0);
        } else{
            system("clear");
        }

    } while (1);

    return 0;
}