evac.out : evac.o EvacRunner.o
	g++ -ansi -Wall -g -o evac.out evac.o EvacRunner.o
evac.o : evac.cpp evac.h 
	g++ -ansi -Wall -g -c evac.cpp
EvacRunner.o : EvacRunner.cpp CPUTimer.h EvacRunner.h evac.h 
	g++ -ansi -Wall -g -c EvacRunner.cpp
clean : 
	rm -f *.o evac.out
