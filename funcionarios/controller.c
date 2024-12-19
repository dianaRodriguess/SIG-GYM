#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "model.h"
#include "controller.h"
#include "../libs/entradas.h"
#include "../libs/utils.h"
#include "../libs/style.h"
#include "../libs/leitura_dados.h"


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
        cadastrarClientes();
        conf = confirmação("funcinario", "você quer mesmo realizar o cadastro");
        switch(conf){
            case '1':
                char* cpf = leCPF();
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
