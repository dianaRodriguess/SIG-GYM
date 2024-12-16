#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "model.h"
#include "controller.h"
#include "../libs/utils.h"
#include "../libs/style.h"
#include "../libs/leitura_dados.h"

void menuCliente(void){
    Cliente* cliente;
    char opcao;
    do {
        opcao = menuClientes();
        switch(opcao){
            case '1':
                limparBuffer();
                cliente = cadastrarCliente();
                if(cliente != NULL){
                    salvarCliente(cliente);
                    free(cliente);
                    pausarTela();
                }
                break;
            case '2':
                limparBuffer();
                listarDados();
                pausarTela();
                break;
            case '3':
                limparBuffer();
                editarDados();
                pausarTela();
                break;
        }
    } while (opcao != '0');
}

Cliente* cadastrarCliente(void){
    char conf;
    int resultado;
    int verificar = 0;
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    if(cliente == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    while (verificar != 1){
        cadastrarClientes();
        conf = confirmação("cliente", "você quer mesmo realizar o cadastro");
        switch(conf){
            case '1':
                char* cpf = leCPF();
                resultado = checaCPF(cpf);
                switch(resultado) {
                    case 1:
                        printf("Cliente reativado com sucesso!\n");
                        verificar = 1;
                        free(cliente);
                        free(cpf);
                        return NULL;
                        break;
                    case 0:
                        strcpy(cliente->cpf, cpf);
                        free(cpf);

                        char* nome = leNome();
                        strcpy(cliente->nome, nome);
                        free(nome);

                        char* telefone = leTelefone();
                        strcpy(cliente->telefone, telefone);
                        free(telefone);

                        char* email = leEmail();
                        strcpy(cliente->email, email);
                        free(email);

                        char* dataNasc = leDataNasc();
                        strcpy(cliente->dataNasc, dataNasc);
                        free(dataNasc);

                        int sexo = leSexo();
                        cliente->sexo = sexo;

                        int plano = lePlano();
                        cliente->plano = plano;

                        cliente->status = 1;

                        verificar = 1;
                        return cliente;
                    case -1:
                        limparTela();
                        printf("Já existe uma conta ativa com esse CPF. Por favor, informe um novo CPF.\n");
                        pausarTela();
                        continue;
                    default:
                        printf("Erro inesperado.\n");
                        free(cpf);
                        free(cliente);
                        return NULL;
                        break;
                    }
            case '0':
                free(cliente);
                return NULL;
            default:
                printf("Opção inválida, tente novamente.\n");
                break;
        }
    }

    return NULL;
}

void listarDados(void){
    exibirDados();
    char* cpf = leCPF();
    Cliente* cliente = carregarClientes(cpf);
    if (cliente == NULL) {
        printf("Cliente não encontrado ou não está ativo.\n");
        free(cliente);
        free(cpf);
        return;
    }

    dadosClientes(cliente);

    free(cliente);
    free(cpf);
}

void editarDados(void) {
    int op;
    char conf;
    int verif = 0;

    do{
        alterarDados();
        conf = confirmação("cliente", "você quer mesmo realizar a alteração dos seus dados");
        switch(conf) {
            case '1':
                limparBuffer();
                char* cpf = leCPF();
                Cliente* cliente = carregarClientes(cpf);
                if(cliente == NULL){
                    printf("Cliente não encontrado ou não está ativo.\n");
                    free(cliente);
                    free(cpf);
                    verif = 1;
                }

                dadosClientes(cliente);
                op = lerOpcao("Selecione o dado que deseja alterar - Somente números: ", 7);
                alteraCliente(cliente, op);
                free(cliente);
                free(cpf);
                verif = 1;
                break;
            case '0':
                verif = 1;
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
                break;
            }
    } while(verif != 1);
}

int main(void){
    menuCliente();
    return 0;
}