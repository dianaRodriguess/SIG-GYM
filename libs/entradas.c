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

void capturarSexo(int *sexo){
    printf("> Selecione um sexo -> 1 - Masculino, 2 - Feminino: ");
    scanf(" %d", sexo);
    getchar();
}

void capturarPlano(int *plano){
    printf("> Selecione um plano -> 1 - Básico, 2 - Intermediário, 3 - Avançado: ");
    scanf(" %d", plano);
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