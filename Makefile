OBJ_DIR = obj

all: create
	gcc -Wall -c */*.c
	gcc -Wall -c *.c
	gcc -o main *.o
	@mv *.o $(OBJ_DIR)

create:
	@mkdir -p $(OBJ_DIR)

run:
	clear
	@./main

clean:
	@rm -rf ./obj
	clear