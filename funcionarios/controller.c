#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "model.h"
#include "controller.h"
#include "../libs/entradas.h"
#include "../libs/utils.h"
#include "../libs/leitura_dados.h"


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
                listarDados();
                pausarTela();
                break;
            case '3':
                limparBuffer();
                editarDados();
                pausarTela();
                break;
            case '4':
                limparBuffer();
                excluirFuncionario();
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
                resultado = checaCPF(cpf);
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

void listarFuncionarios(void){
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

void editarDados(void) {
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

void ativosDadosFuncionarios() {
    limparTela();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                      Funcionários ativos                                                             |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-50s| %-14s  | %-12s | %-20s| %-13s    | %-1s      | %-6s     |\n",
           "Nome", "CPF", "Telefone", "Email", "Data de Nasc ", "Cargo");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir ao arquivo\n");
        return 0;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.status == 1){
            
        }                                           // FALTA DESENVOLVER AQUI
    }





}
