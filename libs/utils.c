#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pausarTela(void) {
    printf("Tecle <ENTER> para continuar.");
    getchar();
}

void limparBuffer(void) {
    int buffer;
    while ((buffer = getchar()) != '\n' && buffer != EOF);
}

char lerOpcaoMain(void) {
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

void limparTela(void) {
    system("clear || cls");
}

void centralizarTexto(char* texto, int tamanho){
    int comprimento = strlen(texto);
    int espacos_esquerda = (tamanho - comprimento) / 2;
    int espacos_direita = tamanho - comprimento - espacos_esquerda;

    for(int i = 0; i < espacos_esquerda; i++){
        fputc(' ', stdout);
    }

    printf("%s", texto);

    for(int i = 0; i < espacos_direita; i++){
        fputc(' ', stdout);
    }
}

const char* nomeSexo(int sexo) {
    switch (sexo) {
        case 1:   return "Masculino";
        case 2:    return "Feminino";
        default:  return "Desconhecido";
    }
}