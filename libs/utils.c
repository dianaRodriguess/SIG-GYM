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

int lerOpcao(const char* msg, int num) {
    int opcao;
    do {
        printf("> %s ", msg);
        scanf(" %d", &opcao);
        limparBuffer();
    } while (opcao < 0 || opcao > num);
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

const char* nomePlano(int plano) {
    switch (plano) {
        case 1:   return "Básico";
        case 2:   return "Intermediário";
        case 3:   return "Avançado";
        default:  return "Desconhecido";
    }
}

char confirmação(const char* pessoa, const char* msg) {
    char op;
    printf("> Caro %s, você quer mesmo realizar %s? - Digite 1 para continuar e 0 para sair: ", pessoa, msg);
    scanf(" %c", &op);
    limparBuffer();
    return op;
}