all: p9.out p9b.out

p9.out: main.cpp BST.cpp BST.h queue.cpp queue.h stack.cpp stack.h
	g++ -Wall -g -ansi -DNDEBUG -o p9.out main.cpp

p9b.out: main.cpp BST.cpp BST.h queue.cpp queue.h stack.cpp stack.h
	g++ -Wall -g -ansi -o p9b.out main.cpp

clean:
	rm p9.out p9b.out
