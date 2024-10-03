#include <stdio.h>

void limparBuffer(void){
    int buffer;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}

char lerOpcao(void){
    char opcao = getchar();
    limparBuffer();
    return opcao;
}