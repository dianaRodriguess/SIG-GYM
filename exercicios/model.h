#ifndef MODEL_H
#define MODEL_H
#define FALSE 0
#define TRUE 1

typedef struct {
    int id_exercicio;   
    char nome[50];       
    char categoria[30];  
    int status;
} Exercicio;

int salvarExercicio(Exercicio*);
Exercicio* carregarExercicio(int id);
void alteraExercicio(Exercicio* exercicio, int op);
int deletarExercicio(Exercicio*);
int checaExercicioID(int id);
int regravaExercicio(Exercicio* exercicio);

#endif