brians_brain_cellular_automata: brians_brain_cellular_automata.o brians_brain.o cell.o cell_grid.o list.o
	gcc -Wall brians_brain_cellular_automata.o brians_brain.o cell.o cell_grid.o list.o -o auto

%.o: %.c
	gcc -Wall -c $<


clean:
	rm *.o
