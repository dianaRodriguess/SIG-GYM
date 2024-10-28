#ifndef ENTRADAS_H
#define ENTRADAS_H

// Funções para capturar strings
void capturarNome(char *nome);
void capturarFuncao(char *funcao);
void capturarMarca(char *marca);
void capturarCPF(char *cpf);
void capturarEndereco(char *endereco);
void capturarTelefone(char *telefone);
void capturarEmail(char *email);
void capturarDataNasc(char *dataNasc);
void capturarCargo(char *cargo);
void capturarMusculos(char *musculos);
void capturarRepeticao(char *repeticao);

// Funções para capturar caracteres
void capturarSexo(char *sexo);
void capturarPlano(char *plano);

// Função para capturar código de barras
void capturarCodBarras(char *codBarras);

// Funções para capturar valores numéricos
void capturarQuantidade(char *quantidade);
void capturarPreco(char *preco);

// Função para limpar o buffer de entrada
void limparBuffer(void);

// Função para pausar a tela
void pausarTela(void);

// Funções para ler opções do menu
char lerOpcaoMain(void);
char lerOpcao(void);

#endif // ENTRADAS_H
