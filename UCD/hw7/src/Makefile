CC = gcc

all: cell_tester cell_grid_tester list_tester brians_brain_cellular_automata

brians_brain_cellular_automata: brians_brain_cellular_automata.c brians_brain.o cell.o cell_grid.o list.o
	gcc -Wall brians_brain_cellular_automata.c brians_brain.o cell.o cell_grid.o list.o -o brians_brain_cellular_automata

%.o: %.c
	$(CC) -Wall -c $<

cell_tester: cell_tester.c cell.o
	$(CC) -Wall cell_tester.c cell.o -o cell_tester -lm

list_tester: list_tester.c list.o cell.o
	$(CC) -Wall list_tester.c list.o cell.o -o list_tester

cell_grid_tester: cell_grid_tester.c cell_grid.o cell.o
	$(CC) -Wall cell_grid_tester.c cell_grid.o cell.o -o cell_grid_tester

clean:
	rm *.o cell_tester cell_grid_tester list_tester brians_brain_cellular_automata
