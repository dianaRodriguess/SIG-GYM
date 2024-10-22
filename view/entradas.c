#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capturarNome(char *nome){
    printf("> Nome: \n");
    fgets(nome, 55, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

void capturarFuncao(char *funcao){
    printf("> Função: \n");
    fgets(funcao, 55, stdin);
    funcao[strcspn(funcao, "\n")] = '\0';
}

void capturarMarca(char *marca){
    printf("> Marca: \n");
    fgets(marca, 15, stdin);
    marca[strcspn(marca, "\n")] = '\0';
}

void capturarCPF(char *cpf){
    printf("> CPF: \n");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
}

void capturarEndereco(char *endereco){
    printf("> Endereço: \n");
    fgets(endereco, 55, stdin);
    endereco[strcspn(endereco, "\n")] = '\0';
}

void capturarTelefone(char *telefone){
    printf("> Telefone: \n");
    fgets(telefone, 15, stdin);
    telefone[strcspn(telefone, "\n")] = '\0';
}

void capturarEmail(char *email){
    printf("> Email: \n");
    fgets(email, 55, stdin);
    email[strcspn(email, "\n")] = '\0';
}

void capturarDataNasc(char *dataNasc){
    printf("> Data de nascimento: \n");
    fgets(dataNasc, 11, stdin);
    dataNasc[strcspn(dataNasc, "\n")] = '\0';
}

void capturarSexo(char *sexo){
    printf("> Sexo: \n");
    scanf(" %c", sexo);
    getchar();
}

void capturarPlano(char *plano){
    printf("> Plano: \n");
    scanf(" %c", plano);
    getchar();
}

void capturarCodBarras(char *codBarras){
    printf("\n>Digite o Código de barras do equipamento (apenas números): \n");
    fgets(codBarras, 13, stdin);
    codBarras[strcspn(codBarras, "\n")] = '\0';
}

void capturarInt(int *quantidade){
    printf("> Quantidade: \n");
    fgets(quantidade, sizeof(quantidade), stdin);
    quantidade[strcspn(quantidade, "\n")] = '\0';
}

void capturarFloat(float *preco){
    printf("> Preço: \n");
    fgets(preco, sizeof(preco), stdin);
    preco[strcspn(preco, "\n")] = '\0';
}

void limparBuffer(void) {
    int buffer;
    while ((buffer = getchar()) != '\n' && buffer != EOF);
}

void pausarTela(void) {
    int pausa;
    printf("Tecle <0> para continuar.\n");
    scanf("%d", &pausa);
    limparBuffer();
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