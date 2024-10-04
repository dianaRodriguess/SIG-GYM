#ifndef LOOPS_H
#define LOOPS_H

void loopCadastrar(void);
void loopPesquisar(void);
void loopAtualizar(void);
void loopDeletar(void);
void loopRelatorios(void);
void processarOpcao(char opcao, 
                    void (*operacaoCliente)(), 
                    void (*operacaoTreino)(), 
                    void (*operacaoFuncionario)(), 
                    void (*operacaoEquipamento)());


#endif