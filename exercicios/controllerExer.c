#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewExer.h"
#include "modelExer.h"
#include "controllerExer.h"
#include "relatoriosExer.h"
#include "../libs/utils.h"
#include "../libs/style.h"
#include "../libs/leitura_dados.h"
#include "../libs/entradas.h"


void menuExercicio(void){
    Exercicio* exercicio;
    char opcao;
    do{
        opcao = menuExercicios();
        switch(opcao){
            case '1':
                limparBuffer();
                exercicio = cadastrarExercicio();
                if(exercicio != NULL){
                    salvarExercicio(exercicio);
                    free(exercicio);
                }
                pausarTela();
                break;
            case '2':
                limparBuffer();
                listarDadosExercicio();
                pausarTela();
                break;
            case '3':
                limparBuffer();
                editarExercicio();
                pausarTela();
                break;
            case '4':
                limparBuffer();
                excluirExercicio();
                pausarTela();
                break;
            case '5':
                limparBuffer();
                menuRelatorioExercicio();
                pausarTela();
                break;
        }
    } while (opcao != '0');
}

Exercicio* cadastrarExercicio(void){
    
    char conf;
    int resultado;
    int verificar = 0;
    Exercicio* exercicio = (Exercicio*)malloc(sizeof(Exercicio));\
    if(exercicio == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    while (verificar != 1){
        menuCadastrarExercicio();
        conf = confirmação("funcionário", "você quer mesmo realizar o cadastro");
        
        switch(conf){
            case '1':
                int id = gerarExercicioID();  
                resultado = checaExercicioID(id);  

                switch(resultado){
                    case 0:
                        exercicio->id_exercicio = id;

                        char* nome = leNome();
                        strcpy(exercicio->nome, nome);
                        free(nome);

                        char* categoria = leFuncao();
                        strcpy(exercicio->categoria, categoria);
                        free(categoria);

                        exercicio->status = 1;
                        verificar = 1;
                        printf("O id do exercício será: %i \n", id);
                        return exercicio;
                    default:
                        printf("Erro inesperado.\n");
                        free(exercicio);
                        return NULL;
                        break;
                }
        case '0':
                free(exercicio);
                return NULL;
            default:
                printf("Opção inválida, tente novamente.\n");
                break;
    }
}
    return NULL;

}

void listarDadosExercicio(void){
    menuExibirExercicio();
    int op;
    int id = 0;
    capturarID(&id);
    Exercicio* exercicio = carregarExercicio(id);
    if (exercicio != NULL) {
        if (exercicio->status == 1) {
            dadosExercicios(exercicio);
            op = lerOpcao("Tecle 0 para continuar." , 1 );
        } 
        else {
            printf("Exercício não encontrado ou não está ativo.\n");
            op = lerOpcao("Tecle 0 para continuar." , 1 );
            
         }
    } else {
        printf("Exercício não encontrado.\n");
        op = lerOpcao("Tecle 0 para continuar." , 1 );
    }
    free(exercicio);
  
}

void editarExercicio(void) {
    int op;
    char conf;
    int verif = 0;

    do {
        menuAtualizarExercicio();
        conf = confirmação("cliente", "você quer mesmo realizar a alteração no seu exercício");

        switch (conf) {
            case '1': {
                limparBuffer();
                int id = 0;
                capturarID(&id);
                Exercicio* exercicio = carregarExercicio(id);

                if (exercicio == NULL || exercicio->status == 0) {
                    printf("Exercício não encontrado ou não está ativo.\n");
                    op = lerOpcao("Tecle 0 para continuar." , 1 );
                    free(exercicio);  
                    break;  
                }

                dadosExercicios(exercicio);

                do {
                    op = lerOpcao("Selecione o dado que deseja alterar - Somente números (1: Nome, 2: Função, 0: Sair): ", 7);
                    if (op == 0) {
                        printf("Nenhuma alteração realizada.\n");
                        break;
                    }
                    alteraExercicio(exercicio, op);
                } while (op != 0);

                free(exercicio);
                break;
            }

            case '0':
                verif = 1;  
                break;

            default:
                printf("Opção inválida, tente novamente.\n");
                break;
        }
    } while (verif != 1);
}




void excluirExercicio(void){
    int op;
    char conf;
    int resultado;
    int verificar = 0;
    Exercicio* exercicio = NULL;
    int id = 0;

    while(verificar != 1){
        conf = confirmação("cliente", "você quer mesmo realizar a exclusão seu exercício");
        switch(conf) {
            case '1':
                capturarID(&id);
                exercicio = carregarExercicio(id);
                if(exercicio != NULL){
                    resultado = deletarExercicio(exercicio);
                    switch(resultado){
                        case 1:
                            printf("Exercício excluído com sucesso!\n");
                            op = lerOpcao("Tecle 0 para continuar." , 1 );
                            break;
                        case -1:
                            printf("Exercício já está inativo.\n");
                            op = lerOpcao("Tecle 0 para continuar." , 1 );
                            break;
                        case -2:
                            printf("Erro inesperado.\n");
                            op = lerOpcao("Tecle 0 para continuar." , 1 );
                            break;
                        default:
                            printf("ERRO!!.\n");
                            op = lerOpcao("Tecle 0 para continuar." , 1 );
                            break;
                    }
                    free(exercicio);
                    verificar = 1;
                } else {
                    printf("Exercício não encontrado.\n");
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

void menuRelatorioExercicio(void) {
    Exercicio* exercicio;
    char opcao;
    char op;
    do{
        opcao = relatorioExercicio();
        switch(opcao){
            case '1':
            do{
                limparBuffer();
                op = statusExercicios();
                switch(op){
                    case '1':
                        limparBuffer();
                        ativosExercicios();
                        pausarTela();
                        break;
                    case '2':
                        limparBuffer();
                        inativosExercicios();
                        pausarTela();
                        break;
                    case '3':
                        limparBuffer();
                        allExercicios();
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
   
     // aqui fica faltando o de ordem alfabetica


    }

    
 }while (opcao != '0');
}