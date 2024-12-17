#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* msgManipCliente(char* funcao, int op){
    if(strcmp(funcao, "salvarCliente") == 0){
        switch(op){
            case 1:
                return "Cliente salvo com sucesso!";
                break;
            case 0:
                return "Erro ao abrir o arquivo";
                break;
            case -1:
                return "Erro ao salvar o cliente";
                break;
            default:
                return "Erro desconhecido";
                break;
        }
    } else if(strcmp(funcao, "regravarClientes") == 0){
        switch (op){
        case 0:
            return "Erro ao abrir o arquivo";
            break;
        case 1:
            return "Cliente regravado com sucesso!";
            break;
        case -1:
            return "Erro a regravar o cliente";
            break;
        case -2:
            return "Cliente não encontrado";
            break;
        default:
            return "Erro desconhecido";
            break;
        }
    } else if(strcmp(funcao, "excluirCliente") == 0){
        switch (op){
        case 0:
            return "Erro ao abrir o arquivo";
            break;
        case 1:
            return "Cliente excluido com sucesso!";
            break;
        case -1:
            return "Erro ao excluir o cliente";
            break;
        case -2:
            return "Cliente não encontrado";
            break;
        default:
            return "Erro desconhecido";
            break;
        }
    } else {
        return "Função não encontrada";
}
}