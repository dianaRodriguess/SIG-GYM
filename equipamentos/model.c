#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "model.h"
#include "../view/entradas.h"

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
int lerArquivoEqui(){

    return TRUE;
}

// atualiza o status do equipamento no arquivo
int atualizarStatusEqui(){

    return TRUE;
}

// atualiza os dados do equipamentos no arquivo
int atualizarDadosEqui(){

    return TRUE;
}
