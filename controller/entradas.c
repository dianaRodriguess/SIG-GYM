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

void pausarSubTela(void){
    int espere;
    do {
        printf("Tecle <0> para continuar.\n");
        scanf("%d", &espere);
        limparBuffer();
    } while (espere != 0);
}

char lerOpcao(void){
    char opcao = getchar();
    limparBuffer();
    return opcao;
}