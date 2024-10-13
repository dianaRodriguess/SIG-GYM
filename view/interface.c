#include <stdio.h>
#include <stdlib.h>
    
void telaPrincipal(void){
    system("clear");
    printf(" _______________________________ \n");
    printf("|.....       SIG-GYM       .....|\n");
    printf("|_______________________________|\n");
    printf("|                               |\n");
    printf("|  1. Módulo Cadastro           |\n");
    printf("|  2. Módulo Pesquisa           |\n");
    printf("|  3. Módulo Atualizar          |\n");
    printf("|  4. Módulo Deletar            |\n");
    printf("|  5. Relatórios                |\n");
    printf("|  6. Informações               |\n");
    printf("|  0. Sair                      |\n");
    printf("|_______________________________|\n\n");
}

void telaCadastro(void){
    system("clear");
    printf(" __________________________________ \n");
    printf("|.....   MÓDULO DE CADASTRO   .....|\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|  1. Cadastrar Cliente            |\n");
    printf("|  2. Cadastrar Treino             |\n");
    printf("|  3. Cadastrar Funcionário        |\n");
    printf("|  4. Cadastrar Equipamento        |\n");
    printf("|  0. Menu principal               |\n");
    printf("|__________________________________|\n\n");
}

void telaPesquisar(void){
    system("clear");
    printf(" __________________________________ \n");
    printf("|.....   MÓDULO DE PESQUISA   .....|\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|  1. Pesquisar Cliente            |\n");
    printf("|  2. Pesquisar Treino             |\n");
    printf("|  3. Pesquisar Funcionário        |\n");
    printf("|  4. Pesquisar Equipamento        |\n");
    printf("|  0. Menu principal               |\n");
    printf("|__________________________________|\n\n");
}

void telaAtualizar(void){
    system("clear");
    printf(" __________________________________ \n");
    printf("|.....   MÓDULO DE ATUALIZAR  .....|\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|  1. Atualizar Cliente            |\n");
    printf("|  2. Atualizar Treino             |\n");
    printf("|  3. Atualizar Funcionário        |\n");
    printf("|  4. Atualizar Equipamento        |\n");
    printf("|  0. Menu principal               |\n");
    printf("|__________________________________|\n\n");
}

void telaDeletar(void){
    system("clear");
    printf(" __________________________________ \n");
    printf("|.....   MÓDULO DE DELETAR    .....|\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|  1. Deletar Cliente              |\n");
    printf("|  2. Deletar Treino               |\n");
    printf("|  3. Deletar Funcionário          |\n");
    printf("|  4. Deletar Equipamento          |\n");
    printf("|  0. Menu principal               |\n");
    printf("|__________________________________|\n\n");
}

void telaRelatorios(void){
    system("clear");
    printf(" __________________________________ \n");
    printf("|.....  MÓDULO DE RELATÓRIOS  .....|\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("|  1. Ver todos os Clientes        |\n");
    printf("|  2. Ver todos os Treinos         |\n");
    printf("|  3. Ver todos os Funcionários    |\n");
    printf("|  4. Ver todos os Equipamentos    |\n");
    printf("|  0. Menu principal               |\n");
    printf("|__________________________________|\n\n");
}


void telaInfo(void){
    system("clear");
    printf(" ___________________________________\n");
    printf("|.....  MÓDULO DE INFORMAÇÕES  .....|\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|  1. Equipe                        |\n");
    printf("|     > Anderson Gabriel            |\n");
    printf("|       > github: anderson-cruz13   |\n");
    printf("|     > Diana Rodrigues             |\n");
    printf("|       > github: dianaRodriguess   |\n");
    printf("|  0. Menu principal                |\n");
    printf("|___________________________________|\n\n");
}

void telaVerCleintes(void){
    system("clear");
    printf("|_________________________________________________________________________________________________________________________________________________|\n");
    printf("|..... . .. .  ...  . .. .  ...  . .. .  ...  .. . ...  . .. . VER TODOS OS CLIENTES . .. .  ...  . .. .  ...  . .. .  ...  .. . ...  . .. . .....|\n");
    printf("|_________________________________________________________________________________________________________________________________________________|\n");
    printf('|___________|_____________________________|_________________|____________________________|_______________________________|________________________|\n');
    printf('|    CPF    |        Nome Completo        |     Telefone    |            Email           |          Logradouro           |         Cidade         |\n');
    printf('|___________|_____________________________|_________________|____________________________|_______________________________|________________________|\n');
}

void telaVerTreinos(void){
    system("clear");
    printf("|________________________________________________________________________________________________________________________|\n");
    printf("|..... . .. .  ...  . .. .  ...  . .. .  ...  ..  . VER TODOS OS TREINOS . .. .  ...  . .. .  ...  .. . ...  . .. . .....|\n");
    printf("|________________________________________________________________________________________________________________________|\n");
    printf('|___________|_____________________________|_________________|____________________________|_______________________________|\n');
    printf('|    Id     |        Titulo               |     Musculos    |         Repetição          |          Cliente              |\n');
    printf('|___________|_____________________________|_________________|____________________________|_______________________________|\n');
}   

void telaVerFuncionarios(void){
    system("clear");
    printf("|________________________________________________________________________________________________________________________________________________________________|\n");
    printf("|..... . .. .  ...  . .. .  ...  . .. .  ...  .. . ...  . .. . ..  . VER TODOS OS FUNCIONÁRIOS . .. . .. .  ...  . .. .  ...  . .. .  ...  .. . ...  . .. . .....|\n");
    printf("|________________________________________________________________________________________________________________________________________________________________|\n");
    printf('|___________|_____________________________|_____________|__________________|____________________________|_______________________________|________________________|\n');
    printf('|    CPF    |        Nome Completo        |    Cargo    |      Telefone    |            Email           |          Logradouro           |         Cidade         |\n');
    printf('|___________|_____________________________|_____________|__________________|____________________________|_______________________________|________________________|\n');
}

void telaVerEquipamentos(void){
    system("clear");
    printf("|___________________________________________________________________________________________________________________________|\n");
    printf("|..... . .. . ... . .. . ... . .. . ... .. . ...  VER TODOS OS EQUIPAMENTOS  ... . .. . ... . .. . ... .. . ... . .. . .....|\n");
    printf("|___________________________________________________________________________________________________________________________|\n");
    printf('|______________|____________________|_____________|________________|___________________________|________________|___________|\n');
    printf('|    Código    |        Nome        |    Marca    |      Função    |         Fabricante        |   Quantidade   |   Preço   |\n');
    printf('|______________|____________________|_____________|________________|___________________________|________________|___________|\n');
    
}