evac.out : evac.o EvacRunner.o MyCity.o MyRoad.o
	g++ -ansi -Wall -g -o evac.out evac.o EvacRunner.o MyCity.o MyRoad.o 

evac.o : evac.cpp evac.h 
	g++ -ansi -Wall -g -c evac.cpp

EvacRunner.o : EvacRunner.cpp CPUTimer.h EvacRunner.h evac.h 
	g++ -ansi -Wall -g -c EvacRunner.cpp
MyCity.o : MyCity.cpp MyCity.h
	g++ -ansi -Wall -g -c MyCity.cpp
MyRoad.o : MyRoad.cpp MyRoad.h
	g++ -ansi -Wall -g -c MyRoad.h
clean : 
	rm -f evac.out evac.o  EvacRunner.o   
