#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/utils.h"
#include "modelExer.h"
#include "../libs/leitura_dados.h"
#include "viewExer.h"

int salvarExercicio(Exercicio* exercicio){
    FILE* arquivo = fopen("exercicios.dat", "ab");
    if(arquivo == NULL){
        return 0;
    }
    if(fwrite(exercicio, sizeof(Exercicio), 1, arquivo) != 1){
        return -1;
    }
    fclose(arquivo);
    return 1;
}

Exercicio* carregarExercicio(int id){
    Exercicio* exercicio = (Exercicio*)malloc(sizeof(Exercicio));
    FILE* arquivo = fopen("exercicios.dat", "rb");
    if(arquivo == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    while(fread(exercicio, sizeof(Exercicio), 1, arquivo)) {
        if (exercicio->id_exercicio == id){
            fclose(arquivo);
            return exercicio;
        }
    }
    fclose(arquivo);
    free(exercicio);
    return NULL;
}

void alteraExercicio(Exercicio* exercicio, int op){
    char* entrada = NULL;

    switch(op){
        case 1:
            limparBuffer();
            entrada = leNome(); // Chama a função e armazena o resultado em entrada
            strcpy(exercicio->nome, entrada); // Copia o valor para o campo nome
            break;

        case 2:
            limparBuffer();
            entrada = leFuncao(); // Chama a função e armazena o resultado em entrada
            strcpy(exercicio->categoria, entrada); // Copia o valor para o campo categoria
            break;

        default:
            printf("Opção inválida\n");
            break;
    }

    regravaExercicio(exercicio); // ainda irei fazer
    dadosExercicios(exercicio); // ainda irei fazer
    if (entrada != NULL){
        free(entrada);
    }
}
int regravaExercicio(Exercicio* exercicio){
    FILE *arquivo = fopen("exercicios.dat", "r+b");
    if(arquivo == NULL){
        return 0;  
    }

    Exercicio* novoExercicio = (Exercicio*)malloc(sizeof(Exercicio));
    if (novoExercicio == NULL) {
        fclose(arquivo);  
        return 0;  
    }

    while (fread(novoExercicio, sizeof(Exercicio), 1 , arquivo)){
        if (novoExercicio->id_exercicio == exercicio->id_exercicio) {
            fseek(arquivo, -sizeof(Exercicio), SEEK_CUR);
            if(fwrite(exercicio, sizeof(Exercicio), 1, arquivo)){
                fclose(arquivo);
                free(novoExercicio);
                return TRUE; 
            } 
            fclose(arquivo);
            free(novoExercicio);
            return -1;  
        }
    }

    fclose(arquivo);
    free(novoExercicio);
    return -2;  // Exercício não encontrado
}


int deletarExercicio(Exercicio* exercicio){
    if(exercicio->status == 1){
        exercicio->status = 0;
        regravaExercicio(exercicio); // ainda irei fazer
        return 1;
    }else{
        return -1;
    }

    return -2;
}

int geraIDExe(void) {
    Exercicio exe;
    FILE* file = fopen("exercicios.dat", "rb");

    if (file == NULL) return 1; // Se o arquivo não existe, começamos do ID 1

    fseek(file, -sizeof(Exercicio), SEEK_END); // Move para o último registro
    fread(&exe, sizeof(Exercicio), 1, file); // Lê o último registro
    fclose(file);

    return exe.id_exercicio + 1; // Retorna o próximo ID válido
}