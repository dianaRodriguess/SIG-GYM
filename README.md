# SIG-GYM
O SIG-GYM é um sistema de gerenciamento de academia.

### Complilação e uso

Passos para compilar o programa:

#### Linux
- 1 - No terminal, vá para do diretório do projeto
- 2 - Use o comando `make` para compilar e gerar os arquivos .o
- 3 - Use o comando `make run` para abrir o programa
- 4 - Se desejado, use o comando `make clean` para remover os arquivos .o e os arquivos executáveis

#### Outras formas
Use os comando a seguir no terminal do <ins>diretório do projeto e em sequência</ins>.

**1º comando:** `gcc -c $(find . -name "*.c")`

**2º comando:** `gcc -o main $(find . -name "*.c")`

**3º comando:** `./main`
