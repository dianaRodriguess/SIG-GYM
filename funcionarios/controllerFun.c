#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewFun.h"
#include "modelFun.h"
#include "controllerFun.h"
#include "../libs/entradas.h"
#include "../libs/utils.h"
#include "../libs/leitura_dados.h"
#include "relatoriosFun.h"


void menuFuncionario(void){
    Funcionario* funcionario;
    char opcao;
    do {
        opcao = menuFuncionarios();
        switch(opcao){
            case '1':
                limparBuffer();
                funcionario = cadastrarFuncionario();
                if(funcionario != NULL){
                    salvarFuncionario(funcionario);
                    free(funcionario);
                }
                pausarTela();
                break;
            case '2':
                limparBuffer();
                listarDadosFun();
                pausarTela();
                break;
            case '3':
                limparBuffer();
                editarDadosFun();
                pausarTela();
                break;
            case '4':
                limparBuffer();
                excluirFuncionario();
                pausarTela();
                break;
            case '5':
                limparBuffer();
                menuRelatorioFuncionario();
                pausarTela();
                break;
        }
    } while (opcao != '0');
}

Funcionario* cadastrarFuncionario(void){
    char conf;
    int resultado;
    int verificar = 0;
    Funcionario* funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if(funcionario == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    while (verificar != 1){
        telaCadastrarFuncionario();
        conf = confirmação("funcinario", "você quer mesmo realizar o cadastro");
        char* cpf;
        switch(conf){
            case '1':
                cpf = leCPF();
                resultado = checaCPFun(cpf);
                switch(resultado) {
                    case 1:
                        printf("Funcinário reativado com sucesso!\n");
                        verificar = 1;
                        free(funcionario);
                        free(cpf);
                        return NULL;
                        break;
                    case 0:
                        strcpy(funcionario->cpf, cpf);
                        free(cpf);

                        char* nome = leNome();
                        strcpy(funcionario->nome, nome);
                        free(nome);

                        char* telefone = leTelefone();
                        strcpy(funcionario->telefone, telefone);
                        free(telefone);

                        char* email = leEmail();
                        strcpy(funcionario->email, email);
                        free(email);

                        char* dataNasc = leDataNasc();
                        strcpy(funcionario->dataNasc, dataNasc);
                        free(dataNasc);

                        Cargo cargo = leCargo();
                        funcionario->cargo = cargo;

                        funcionario->status = 1;

                        verificar = 1;
                        return funcionario;
                    case -1:
                        limparTela();
                        printf("Já existe uma conta ativa com esse CPF. Por favor, informe um novo CPF.\n");
                        pausarTela();
                        continue;
                    default:
                        printf("Erro inesperado.\n");
                        free(cpf);
                        free(funcionario);
                        return NULL;
                        break;
                    }
            case '0':
                free(funcionario);
                return NULL;
            default:
                printf("Opção inválida, tente novamente.\n");
                break;
        }
    }

    return NULL;
}

void listarDadosFun(void){
    telaExibirDados();
    char* cpf = leCPF();
    Funcionario* funcionario = carregarFuncionarios(cpf);
    if (funcionario != NULL) {
        if (funcionario->status == 1) {
            dadosFuncionarios(funcionario);
        } else {
            printf("Funcionário não encontrado ou não está ativo.\n");
        }
        free(funcionario);
    } else {
        printf("Funcionário não encontrado.\n");
    }
    free(cpf);    
}

void editarDadosFun(void) {
    int op;
    char conf;
    int verif = 0;

    do{
        telaAlterarDados();
        conf = confirmação("funcionario", "você quer mesmo realizar a alteração dos seus dados");
        switch(conf) {
            case '1':
                limparBuffer();
                char* cpf = leCPF();
                Funcionario* funcionario = carregarFuncionarios(cpf);
                if(funcionario == NULL){
                    printf("Funcinario não encontrado ou não está ativo.\n");
                    free(funcionario);
                    free(cpf);
                    verif = 1;
                }

                dadosFuncionarios(funcionario);
                op = lerOpcao("Selecione o dado que deseja alterar - Somente números: ", 6);
                alteraFuncionario(funcionario, op);
                free(funcionario);
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

void excluirFuncionario(void) {
    char conf;
    int resultado;
    int verificar = 0;
    Funcionario* funcionario = NULL;
    char* cpf = NULL;

    while(verificar != 1) {
        conf = confirmação("funcionario", "você quer mesmo realizar a exclusão da sua conta");
        switch(conf) {
            case '1':
                cpf = leCPF();
                funcionario = carregarFuncionarios(cpf);
                if(funcionario != NULL) {
                    resultado = deletarFuncionario(funcionario);
                    switch(resultado) {
                        case 1:
                            printf("Funcinario excluído com sucesso!\n");
                            break;
                        case -1:
                            printf("Funcinario já está inativo.\n");
                            break;
                        case -2:
                            printf("Erro inesperado.\n");
                            break;
                        default:
                            printf("ERRO!!.\n");
                            break;
                    }
                    free(funcionario);
                    free(cpf);
                    verificar = 1;
                } else {
                    printf("Funcinario não encontrado.\n");
                    free(cpf);
                    verificar = 1;
                }
                break;
            case '0':
                limparTela();
                printf("Operação cancelada.\n");
                verificar = 1;
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
                continue;
        }
    }
}

void menuRelatorioFuncionario(void) {
    char opcao;
    char op;

    do {
        opcao = relatorioFuncionarios(); 
        switch (opcao) {
            case '1': 
                do {
                    limparBuffer();
                    op = statusFuncionarios(); 
                    switch (op) {
                        case '1':
                            limparBuffer();
                            ativosDadosFuncionarios();
                            pausarTela();
                            break;
                        case '2':
                            limparBuffer();
                            inativosDadosFuncionarios();
                            pausarTela();
                            break;
                        case '3':
                            limparBuffer();
                            allFuncionarios();
                            pausarTela();
                            break;
                        case '0': 
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");
                            pausarTela();
                            break;
                    }
                } while (op != '0');
                break;

            case '2': 
                do {
                    limparBuffer();
                    op = cargoFuncionarios(); 
                    switch (op) {
                        case '1':
                            limparBuffer();
                            dadosFuncionariosGerente();
                            pausarTela();
                            break;
                        case '2':
                            limparBuffer();
                            dadosFuncionariosProfessor();
                            pausarTela();
                            break;
                        case '3':
                            limparBuffer();
                            dadosFuncionariosASG();
                            pausarTela();
                            break;
                        case '4':
                            limparBuffer();
                            dadosFuncionariosAtendente();
                            pausarTela();
                            break;
                        case '0': 
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");
                            pausarTela();
                            break;
                    }
                } while (op != '0');
                break;

            case '3':
                limparBuffer();
                allFuncionariosOrdenados();
                pausarTela();
                break;

            
            case '0': 
                printf("Saindo do menu de relatórios.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                pausarTela();
                break;

        }
    } while (opcao != '0'); 
}