p8.out: main.o indexpager.o pager.o
	g++ -Wall -g -ansi main.o indexpager.o pager.o -o p8.out

main.o: main.cpp
	g++ -Wall -c -g -ansi main.cpp

indexpager.o: indexpager.cpp
	g++ -Wall -c -g -ansi indexpager.cpp

pager.o: pager.cpp
	g++ -Wall -c -g -ansi pager.cpp

clean:
	rm main.o indexpager.o pager.o
