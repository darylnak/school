all: p9.out p9b.out
	

p9.out : BST.cpp main.cpp queue.cpp stack.cpp queue.h stack.h BST.h  
	g++ -ansi -Wall -DNDEBUG -o p9.out main.cpp   

p9b.out : BST.cpp main.cpp queue.cpp stack.cpp queue.h stack.h BST.h 
	g++ -ansi -Wall -o p9b.out main.cpp   

clean : 
	rm -f p9.out p9b.out   
