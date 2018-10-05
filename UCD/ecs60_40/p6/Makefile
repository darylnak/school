calendar.out : appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappt.o vector.cpp vector.h linkedlist.cpp linkedlist.h
	g++ -ansi -Wall -o calendar.out appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappt.o

appt.o : appt.cpp appt.h time.h
	g++ -ansi -Wall -c appt.cpp

calendar.o : calendar.cpp calendar.h day.h
	g++ -ansi -Wall -c calendar.cpp

day.o : day.cpp day.h appt.h DayOfWeek.h
	g++ -ansi -Wall -c day.cpp

DayOfWeek.o : DayOfWeek.cpp DayOfWeek.h
	g++ -ansi -Wall -c DayOfWeek.cpp

main.o : main.cpp calendar.h appt.h
	g++ -ansi -Wall -c main.cpp

time.o : time.cpp time.h
	g++ -ansi -Wall -c time.cpp

weeklyappt.o : weeklyappt.cpp weeklyappt.h
	g++ -ansi -Wall -c weeklyappt.cpp

clean :
	rm -f calendar.out appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappt.o
