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
    int resultado;
    do {
        opcao = menuClientes();
        switch(opcao){
            case '1':
                limparBuffer();
                cliente = cadastrarCliente();
                resultado = salvarCliente(cliente);
                msgManipCliente("salvarClientes", resultado);
                free(cliente);
                pausarTela();
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
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    if(cliente == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    cadastrarClientes();

    char* cpf = leCPF();
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

    return cliente;
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
        conf = confirmação("cliente", "a alteração dos seus dados");
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