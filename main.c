#include <stdio.h>
#include <stdlib.h>
#include "view/interface.c"

void limparBuffer(void){
    int buffer;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}


int main(void){
    char opmprin, opmsub; // opmprin = menu principal, opmsub = submenus
    int pausa; // pausa = para pausar o programa para poder ver o cabecalho.
    // pode ser descartada mais na frente

    do{
        opmprin = telaPrincipal();
        switch(opmprin){
            case '1':
                opmsub = telaCadastro();
                switch (opmsub) {
                    case '1':
                        cabecalhos("MÓDULO DE CADASTRO - CADASTRAR CLIENTE");
                        scanf("%d", &pausa);
                        getchar();
                        break;
                    
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                break;
            case '2':
                opmsub = telaPesquisar();
                switch (opmsub) {
                    case '1':
                        cabecalhos("MÓDULO DE PESQUISA - PESQUISAR CLIENTE");
                        scanf("%d", &pausa);
                        getchar();
                        break;
                    
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                break;
            case '3':
                opmsub = telaAtualizar();
                switch (opmsub) {
                    case '1':
                        cabecalhos("MÓDULO DE ATUALIZAR - ATUALIZAR CLIENTE");
                        scanf("%d", &pausa);
                        getchar();
                        break;
                    
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                break;
            case '4':
                opmsub = telaDeletar();
                switch (opmsub) {
                    case '1':
                        cabecalhos("MÓDULO DE DELETAR - DELETAR CLIENTE");
                        scanf("%d", &pausa);
                        getchar();
                        break;
                    
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                break;
            case '5':
                telaRelatorios();
                break;
            case '6':
                telaInfo();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opmprin != '0');

    return 0;
}