#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capturarNome(char *nome){
    printf("> Nome: ");
    fgets(nome, 55, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

void capturarCargo(char *cargo){
    printf("> Cargo: ");
    fgets(cargo, 22, stdin);
    cargo[strcspn(cargo, "\n")] = '\0';
}

void capturarMusculos(char *musculos){
    printf("> Musculos: ");
    fgets(musculos, 62, stdin);
    musculos[strcspn(musculos, "\n")] = '\0';
}

void capturarRepeticao(char *repeticao){
    printf("> Repetição: ");
    fgets(repeticao, 32, stdin);
    repeticao[strcspn(repeticao, "\n")] = '\0';
}

void capturarCodTreino(char *codTreino){
    printf("> Código do treino: ");
    fgets(codTreino, 6, stdin);
    codTreino[strcspn(codTreino, "\n")] = '\0';
}

void capturarFuncao(char *funcao){
    printf("> Função: ");
    fgets(funcao, 55, stdin);
    funcao[strcspn(funcao, "\n")] = '\0';
}

void capturarMarca(char *marca){
    printf("> Marca: ");
    fgets(marca, 15, stdin);
    marca[strcspn(marca, "\n")] = '\0';
}

void capturarCPF(char *cpf){
    printf("> CPF: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
}

void capturarTelefone(char *telefone){
    printf("> Telefone: ");
    fgets(telefone, 15, stdin);
    telefone[strcspn(telefone, "\n")] = '\0';
}

void capturarEmail(char *email){
    printf("> Email: ");
    fgets(email, 55, stdin);
    email[strcspn(email, "\n")] = '\0';
}

void capturarDataNasc(char *dataNasc){
    printf("> Data de nascimento (dd/mm/aaaa): ");
    fgets(dataNasc, 11, stdin);
    dataNasc[strcspn(dataNasc, "\n")] = '\0';
}

void capturarSexo(char *sexo){
    printf("> Sexo: ");
    scanf(" %c", sexo);
    getchar();
}

void capturarPlano(char *plano){
    printf("> Plano: ");
    scanf(" %c", plano);
    getchar();
}

void capturarCodBarras(int* codBarras){
    printf("\n>Digite o Código de barras do equipamento (apenas números): ");
    scanf(" %d", codBarras);
    getchar();
}

void capturarQuantidade(int* quantidade){
    printf("> Quantidade: ");
    scanf(" %d", quantidade);
    getchar();
}

void capturarPreco(float* preco){
    printf("> Preço: ");
    scanf(" %f", preco);
    getchar();
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