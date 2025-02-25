#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelEqui.h"
#include "viewEqui.h"
#include "controllerEqui.h"
#include "../libs/utils.h"
#include "../libs/entradas.h"
#include "relatoriosEqui.h"
#include "../libs/leitura_dados.h"

void menuEquipamentos(void){
    Equipamento* equipamento;
    char opcao;
    do {
        opcao = menuEqui();
        switch(opcao){
            case '1':
                limparBuffer();
                equipamento = CadastroEquipamento();
                if (equipamento != NULL){
                    salvarEquipamento(equipamento);
                    free(equipamento);
                }
                pausarTela();
                break;
            case '2':
                limparBuffer();
                listarEquipamento();
                pausarTela();
                break;
            case '3':
                limparBuffer();
                editarEquipamento();
                pausarTela();
                break;
            case '4':
                limparBuffer();
                excluirEquipamento();
                pausarTela();
                break;
            case '5':
                limparBuffer();
                menuRelatorioEquipamento();
                pausarTela();
                break;
        }
    } while(opcao != '0');
}

Equipamento* CadastroEquipamento(void){
    char conf;
    int verificar = 0;
    Equipamento* equipamento = (Equipamento*) malloc(sizeof(Equipamento));
    if(equipamento == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    while (verificar != 1){
        cadastrarEqui();
        conf = confirmação("funcionário", "você quer mesmo realizar o cadastro");
        switch(conf){
            case '1':
                int id = geraIDEqui();
                equipamento->ID = id;

                char* nome = leNome();
                strcpy(equipamento->nome, nome);
                free(nome);    
                
                char* marca = leMarca();
                strcpy(equipamento->marca, marca);
                free(marca);

                int quantidade = leQuantidade(); 
                equipamento->quantidade = quantidade;

                float preco = lePreco();  
                equipamento->preco = preco;

                equipamento->status = 1;
                verificar = 1;
                return equipamento;
            case '0':
                free(equipamento);
                verificar = 1;
                return NULL;
            default:
                printf("Opção inválida, tente novamente.\n");
                break;    
        }   
    }
    return NULL;
} 

void listarEquipamento(void){
    exibirDadosEqui();
    char conf;
    conf = confirmação("funcionário", "você quer mesmo listar os equipamentos");
    switch(conf){
        case '1':
            limparTela();
            listarEquipamentosAtivos();
            break;
        case '0':
            printf("Operação cancelada.\n");
            break;
    }
}

void editarEquipamento(void){
    int op;
    int conf;
    int verif = 0;

    do{
        alterarDadosEqui();
        conf = confirmação("funcionário", "você quer mesmo realizar a alteração dos seus dados");
        switch(conf){
            case '1':
                limparBuffer();
                listarEquipamentosAtivos();
                numDadosEqui();
                int id = leID();
                Equipamento* equipamento = carregarEquipamentos(id);
                if(equipamento == NULL){
                    printf("Equipamento não encontrado ou não está ativo.\n");
                    free(equipamento);
                    verif = 1;
                    return;
                }

                op = lerOpcao("Selecione o dado que deseja alterar - Somente números: ", 4);
                alteraEquipamento(equipamento, op);
                free(equipamento);
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

void excluirEquipamento(void){
    char conf;
    int resultado;
    int verificar = 0;
    Equipamento* equipamento = NULL;

    while(verificar != 1){
        excluiEquipamento();
        conf = confirmação("funcionário", "você quer mesmo realizar a exclusão do equipamento");
        switch(conf) {
            case '1':
                listarEquipamentosAtivos();
                int id = leID();
                equipamento = carregarEquipamentos(id);
                if(equipamento != NULL){
                    resultado = deletarEquipamento(equipamento);
                    switch(resultado){
                        case 1:
                            printf("Equipamento excluído com sucesso!\n");
                            break;
                        case -1:
                            printf("Equipamento já está inativo.\n");
                            break;
                        case -2:
                            printf("Erro inesperado.\n");
                            break;
                        default:
                            printf("ERRO!!.\n");
                            break;    
                    }
                    free(equipamento);
                    verificar = 1;
                } else {
                    printf("Equipamento não encontrado.\n");
                    verificar = 0;
                }
                break;
            case '0':
                limparTela();
                printf("Operação cancelada\n");
                verificar = 1;
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
                continue;
        }
    }
}

void menuRelatorioEquipamento(void){
    char opcao; 
    char op;
    do{
        opcao = relatorioEquipamentos();
        switch(opcao){
            case '1':
            do{
                limparBuffer();
            op = statusEquipamentos();
            switch(op){
                case '1':
                    limparBuffer();
                    listarEquipamentosAtivos();
                    pausarTela();
                    break;
                case '2':
                    limparBuffer();
                    listarEquipamentosInativos();
                    pausarTela();
                    break;
                case '3':
                    limparBuffer();
                    allEquipamentos();
                    pausarTela();
                    break;


            }
        } while(op != '0');

            case '2':
                limparBuffer();
                allEquipamentosOrdenado();
                pausarTela();
                break;
        }
    }while(opcao != '0');
}