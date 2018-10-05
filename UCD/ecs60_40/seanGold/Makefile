evacGold.out : evac.o EvacRunner.o  
	g++ -ansi -Wall -o evacGold.out evac.o EvacRunner.o  

evac.o : evac.cpp evac.h 
	g++ -ansi -Wall -c evac.cpp

EvacRunner.o : EvacRunner.cpp CPUTimer.h EvacRunner.h evac.h 
	g++ -ansi -Wall -c EvacRunner.cpp

clean : 
	rm -f evac.out evac.o  EvacRunner.o   
