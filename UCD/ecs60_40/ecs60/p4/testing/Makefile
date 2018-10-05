defrag.out: defragmenter.o DefragRunner.o QuadraticProbing.o mynew.o
	g++ -ansi -Wall -g -o defrag.out defragmenter.o DefragRunner.o mynew.o QuadraticProbing.o -pg
defragmenter.o: defragmenter.cpp defragmenter.h
	g++ -ansi -Wall -g -c defragmenter.cpp -pg
DefragRunner.o : DefragRunner.cpp DefragRunner.h mynew.h CPUTimer.h defragmenter.h
	g++ -ansi -Wall -g -c DefragRunner.cpp -pg
mynew.o : mynew.cpp mynew.h
	g++ -ansi -Wall -g -c mynew.cpp -pg
QuadraticProbing.o : QuadraticProbing.cpp QuadraticProbing.h
	g++ -ansi -Wall -g -c QuadraticProbing.cpp -pg
clean:
	rm *.o defrag.out
