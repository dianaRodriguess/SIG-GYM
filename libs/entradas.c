#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capturarNome(char *nome){
    printf("> Nome: ");
    fgets(nome, 55, stdin);
    nome[strcspn(nome, "\n")] = '\0';
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

void capturarCargo(int *cargo){
    printf("> Selecione um plano -> 1 - Gerente, 2 - Professor, 3 - ASG, 4 - Atendente: ");
    scanf(" %d", cargo);
    getchar();
}

void capturarIDequi(char* id){
    printf("\n>Digite o ID do equipamento (apenas números): ");
    fgets(id, 6, stdin);
    id[strcspn(id, "\n")] = '\0';
}

void capturarQuantidade(char* quantidade){
    printf("> Quantidade: ");
    fgets(quantidade, 26, stdin);
    quantidade[strcspn(quantidade, "\n")] = '\0';
}

void capturarPreco(char* preco){
    printf("> Preço: ");
    fgets(preco, 13, stdin);
    preco[strcspn(preco, "\n")] = '\0';
}

void capturarNomeEqui(char *nome){
    printf("> Nome do Equipamento: ");
    fgets(nome, 31, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

void capturarIDExe(char* id){
    printf("\n>Digite o ID do exercício (apenas números): ");
    fgets(id, 6, stdin);
    id[strcspn(id, "\n")] = '\0';
}