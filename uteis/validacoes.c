#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valida_telefone(char* numero) {
    int ddd;
    int ddd_valido = 0;
    int ddds_validos[] = {11, 12, 13, 14, 15, 16, 17, 18, 19,
                          21, 22, 24, 27, 28, 31, 32, 33, 34, 35,
                          37, 38, 41, 42, 43, 44, 45, 46, 47, 48,
                          49, 51, 53, 54, 55, 61, 62, 64, 63, 65,
                          66, 67, 68, 69, 71, 73, 74, 75, 77, 79,
                          81, 82, 83, 84, 85, 86, 87, 88, 89, 91,
                          92, 93, 94, 95, 96, 97, 98, 99}; // DDDs válidos no Brasil
    
    if(strlen(numero) != 11){
        return 0;
    } // Verifica se o número fornecido tem 11 caracteres

    for(int i = 0; i < 11; i++){ // Verifica se todos os caracteres são digitos
        if(!isdigit(numero[i])){
            return 0; 
        }
    }

    ddd = (numero[0] - '0') * 10 + (numero[1] - '0'); // Transforma os dois primeiros digitos em inteiros e armazena na váriavel ddd
    for(int i = 0; i < 67; i++){
        if(ddds_validos[i] == ddd){
            ddd_valido =1;
            break;
        }
    }

    if (ddd_valido == 0) { // Verifica se o ddd é válido
        return 0; 
    }

    if(numero[2] != '9'){ // Verifica se o digito depois do ddd é 9 (formato padrão do Brasil)
        return 0;
    }
    
    return 1; // Número Válido
}