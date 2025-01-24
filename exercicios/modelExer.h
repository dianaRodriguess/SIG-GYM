#ifndef MODELEXER_H
#define MODELEXER_H
#define FALSE 0
#define TRUE 1

typedef struct {
    int id_exercicio;   
    char nome[50];       
    char categoria[30];  
    int status;
} Exercicio;

typedef struct ExercicioNo{
    Exercicio exercicio;
    struct ExercicioNo* proximo;
} ExercicioNo;

int salvarExercicio(Exercicio*);
Exercicio* carregarExercicio(int);
void alteraExercicio(Exercicio*, int);
int deletarExercicio(Exercicio*);
int regravaExercicio(Exercicio*);
int geraIDExe(void);

#endif