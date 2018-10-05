calendar.out : appt.o calendar.o day.o main.o time.o  
	g++ -o calendar.out appt.o calendar.o day.o main.o time.o  

appt.o : appt.cpp appt.h time.h 
	g++ -ansi -Wall -g  -c appt.cpp

calendar.o : calendar.cpp calendar.h day.h 
	g++ -ansi -Wall -g  -c calendar.cpp

day.o : day.cpp day.h appt.h 
	g++ -ansi -Wall -g  -c day.cpp

main.o : main.cpp calendar.h 
	g++ -ansi -Wall -g  -c main.cpp

time.o : time.cpp time.h 
	g++ -ansi -Wall -g  -c time.cpp

clean : 
	rm -f calendar.out appt.o  calendar.o  day.o  main.o  time.o   
