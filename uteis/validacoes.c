#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "validacoes.h"

int verifica_digito(char* array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(array[i])) {
            return 0; // Retorna 0 se algum caractere não for dígito
        }
    }
    return 1; // Retorna 1 se todos os caracteres forem dígitos
}

int veri_num_iguais(char* array, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        if (array[i] != array[0]) {
            return 1; // Retorna 1 se encontrar um dígito diferente
        }
    }
    return 0; // Retorna 0 se todos os dígitos forem iguais
}

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

int valida_cpf(char* cpf) { // 
    int digito1 = 0, digito2 = 0;

    if(strlen(cpf) != 11){
        return 0; 
    } // Verifica se o vetor fornecido tem 11 caracteres

    if(!verifica_digito(cpf, 11)){
        return 0;
    }

    if(!veri_num_iguais(cpf, 11)){
        return 0; // Todos os digitos são iguais
    }

    for(int i = 0; i < 9; i++){
        digito1 += (cpf[i] - '0') * (10 - i);
    } // Faz a multiplicação e a soma do primeiro digito verificador

    digito1 %= 11;
    digito1 = (digito1 < 2) ? 0 : 11 - digito1;

    if(cpf[9] - '0' != digito1){
        return 0; // Verifica se o primeiro dígito verificador corresponde ao cálculo de validação
    }

    for(int i = 0; i < 10; i++){
        digito2 += (cpf[i] - '0') * (11 - i);
    } // Faz a multiplicação e a soma do segundo digito verificador

    digito2 %= 11;
    digito2 = (digito2 < 2) ? 0 : 11 - digito2;

    if(cpf[10] - '0' != digito2){
        return 0; // Verifica se o segundo dígito verificador corresponde ao cálculo de validação
    }

    return 1;
}

DataAtual obter_data_atual(void) {
    time_t t = time(NULL);
    struct tm* data = localtime(&t);
    DataAtual dataAtual;

    dataAtual.dia = data->tm_mday;
    dataAtual.mes = data->tm_mon + 1;
    dataAtual.ano = data->tm_year + 1900;

    return dataAtual;
}

int ano_bissexto(int ano) {
    return ((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0) ? 1 : 0;
} // Adaptada por - Paulo Douglas // Autor - ChatGPT

int valida_data(int dia, int mes, int ano) {
    DataAtual dataAtual = obter_data_atual();

    if(ano > dataAtual.ano){
        return 0; // Verifica se é um ano do futuro
    }

    if(ano < dataAtual.ano - 90){
        return 0; // Ano informado é muito antigo 
    }

    if(mes < 1 || mes > 12){
        return 0; // Mês inválido
    }

    if(dia < 1) {
        return 0; // Dia deve ser maior que 0
    }

    // Verifica os dias máximos para cada mês
    if (mes == 2) {
        if(ano_bissexto(ano)) {
            if(dia > 29){
                return 0; // Fevereiro em ano bissexto não pode ter mais de 29 dias
            }
        } else if(dia > 28) {
            return 0; // Fevereiro em ano não bissexto não pode ter mais de 28 dias
        }
    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if(dia > 30) {
            return 0; // Abril, Junho, Setembro e Novembro têm 30 dias
        }
    } else { // Meses de 31 dias
        if(dia > 31) {
            return 0; // Janeiro, Março, Maio, Julho, Agosto, Outubro e Dezembro têm 31 dias
        }
    }

    return 1; // Data válida
}