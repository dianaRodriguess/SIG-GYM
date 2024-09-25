#include <stdio.h>
#include "view/interface.c"

int main(void){
    int opcao;

    do
    {
        opcao = telaPrincipal();

        if(opcao == 0){
            printf("Saindo...\n");
            break;
        }

        int escolha;
        do
        {
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
                default:
                    printf("Opção inválida!\n");
                    break;
            }

        } while (escolha != 0);
        

    } while (1);
    

    return 0;
}