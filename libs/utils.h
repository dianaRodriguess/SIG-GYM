#ifndef UTILS_H
#define UTILS_H

void limparBuffer(void);
void pausarTela(void);
char lerOpcaoMain(void);
int lerOpcao(const char*, int);
void limparTela(void);
void centralizarTexto(char*, int);
const char* nomeSexo(int);
const char* nomePlano(int);
const char* nomeCargo(int);
char confirmação(const char*, const char*);
int idExisteExercicio(int codigo);
int gerarExercicioID();
int gerarEquipamentoID();
int idExisteEquipamento(int codigo);

#endif