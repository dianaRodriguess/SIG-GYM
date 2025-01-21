#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "view.h"
#include "controller.h"
#include "../libs/entradas.h"
#include "../libs/leitura_dados.h"
#include "../libs/utils.h"

char menuEquipamentos(void){
    Equipamento* equipamento;
    char opcao;
    do {
        opcao = menuEquipamentos();
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
                listarEquipamento(); // ajeitar depois a funcao que esta errada
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
                int id = geraID();
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
    exibirDados();
    char* codBarras;
    Equipamento* equipamento = carregarEquipamentos(codBarras);
    if (equipamento != NULL){
        if(equipamento->status == 1){
            dadosEquipamentos(equipamento);
        } else {
            printf("Equipamento não encontrado ou não está ativo.\n");
        }
        free(equipamento);
    }else{
        printf("Equipamento não encontrado;\n");
    }
    free(codBarras);


}

void editarEquipamento(void){
    int op;
    int conf;
    int verif = 0;

    do{
        alterarDados();
        conf = confirmação("funcionário", "você quer mesmo realizar a alteração dos seus dados");
        switch(conf){
            case '1':
                limparBuffer();
                char* codBarras;
                Equipamento* equipamento = carregarEquipamentos(codBarras);
                if(equipamento == NULL){
                    printf("Equipamento não encontrado ou não está ativo.\n");
                    free(equipamento);
                    free(codBarras);
                    verif = 1;
            }

                dadosEquipamentos(equipamento);
                op = lerOpcao("Selecione o dado que deseja alterar - Somente números: ", 7);
                alteraEquipamento(equipamento, op);
                free(equipamento);
                free(codBarras);
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
    char* codBarras = NULL;

    while(verificar != 1){
        conf = confirmação("funcionário", "você quer mesmo realizar a exclusão do equipamento");
        switch(conf) {
            case '1':
                char* codBarras;  // tem que fazer uma funcao para ler codBarras
                equipamento = carregarEquipamentos(codBarras);
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
                    free(codBarras);
                    verificar = 1;
                } else {
                    printf("Equipamento não encontrado.\n");
                    free(codBarras);
                    verificar = 1;
                }
                break;
            case '0':
                limparTela();
                printf("Operação cancelada");
                verificar = 1;
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
                continue;
        }
    }
}


