#include "model.h"
#include "../libs/leitura_dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void salvarCliente(Cliente* cliente){
    FILE* arquivo = fopen("clientes.dat", "ab");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    fwrite(cliente, sizeof(Cliente), 1, arquivo);
    fclose(arquivo);
    free(cliente);
}