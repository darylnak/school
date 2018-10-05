p8.out : pager.o main.o indexpager.o
	g++ -o p8.out -Wall pager.o main.o indexpager.o

main.o : main.cpp pager.h indexpager.h
	g++ -c -Wall main.cpp

pager.o : pager.cpp pager.h
	g++ -c -Wall pager.cpp

indexpager.o : indexpager.cpp indexpager.h pager.h
	g++ -c -Wall indexpager.cpp

clean:
	rm -f main.o pager.o indexpager.o p8.out
