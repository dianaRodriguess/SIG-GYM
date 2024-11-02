# SIG-GYM
O SIG-GYM é um sistema de gerenciamento de academia.

### Complilação e uso

Passos para compilar o programa:

#### Para a avaliação

As entregas das semanas estão estruturadas em tags assim como mostrado na tabela a seguir

|  Tag  |  Entrega  |
| ----- | --------- |
| v0.1  | Semana 1  |
| v0.2  | Semana 2  |
| v0.3  | Semana 3  |
| v0.4  | Semana 4  |
| v0.5  | Semana 5  |
| v0.6  | Semana 6  |

O arquivo Make file só está disponível a partir da semana 3, portando a compilação das semanas 1 e 2 devem ser feitas usando os comandos padrões.
- `gcc -Wall -c main.c`
- `gcc -o main main.o`
- `./main`

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

