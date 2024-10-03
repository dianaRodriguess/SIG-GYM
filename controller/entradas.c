#include <stdio.h>

void limparBuffer(void){
    int buffer;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}

void pausarTela(void){
    int pausa;
    scanf("%d", &pausa);
    limparBuffer();
}

char lerOpcao(void){
    char opcao = getchar();
    limparBuffer();
    return opcao;
}