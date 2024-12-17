#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "model.h"
#include "../libs/entradas.h"

// escreve no arquivo de equipamentos
int escreverNoArquivoEqui(Equipamento* equi){
    struct stat st = {0};
    if (stat("data/", &st) == -1) {
        if (mkdir("data/", 0700) != 0) {
            printf("Erro ao criar o diretório 'data'\n");
            return FALSE;
        }
    }

    FILE *arq = fopen("data/equipamentos.txt", "a"); // abre o arquivo para leitura e escrita

    if(arq == NULL) { 
        printf("erro ao abrir o arquivo de equipamentos\n"); 
        return FALSE;
    }

    fprintf(arq, "%s:%s:%s:%d:%d:%.2f:%d:\n", equi->nome, equi->marca, equi->funcao, equi->codBarras, equi->quantidade, equi->preco, equi->status);

    fclose(arq);
    return TRUE;
}

// ler o arquivo de equipamentos
int lerArquivoEqui(Equipamento* equi, int codigoBuscado){
    FILE *arq = fopen("data/equipamentos.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de equipamentos\n");
        return FALSE;
    }

    char linha[256]; // armazena uma linha do arquivo
    while (fgets(linha, sizeof(linha), arq)) { // ler cada linha
        
        int codBarras, quantidade, status;
        float preco;
        char nome[55], marca[27], funcao[27];

        if (sscanf(linha, "%54[^:]:%26[^:]:%26[^:]:%d:%d:%f:%d:", 
                   nome, marca, funcao, &codBarras, &quantidade, &preco, &status) == 7) {
            if (codBarras == codigoBuscado) {
                // Preenche a estrutura com os dados encontrados
                strcpy(equi->nome, nome);
                strcpy(equi->marca, marca);
                strcpy(equi->funcao, funcao);
                equi->codBarras = codBarras;
                equi->quantidade = quantidade;
                equi->preco = preco;
                equi->status = status;

                fclose(arq);
                return TRUE;
            }
        }
    }

    // Se o código não for encontrado
    fclose(arq);
    return FALSE;
}

// atualiza o status do equipamento no arquivo
int atualizarStatusEqui(){

    return TRUE;
}

// atualiza os dados do equipamentos no arquivo
int atualizarDadosEqui(){

    return TRUE;
}
