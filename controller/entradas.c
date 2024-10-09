#include <stdio.h>

void limparBuffer(void){
    int buffer;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}

void pausarTela(void){
    int pausa;
    printf("Tecle <0> para continuar.\n");
    scanf("%d", &pausa);
    limparBuffer();
}

char lerOpcaoMain(void){
    char opcao;
    do {
        printf("> Selecione o módulo:\n");
        opcao = getchar();
        limparBuffer();
    } while (opcao < '0' || opcao > '6');
    return opcao;
}

char lerOpcao(void) {
    char opcao;
    do {
        printf("> Selecione uma opção válida:\n");
        opcao = getchar();
        limparBuffer();
    } while (opcao < '0' || opcao > '4');
    return opcao;
}