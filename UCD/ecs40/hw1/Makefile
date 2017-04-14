calendar: main.o calendar.o appt.o day.o time.o
	g++ main.o calendar.o appt.o day.o time.o -g -Wall -o calendar.out

main.o: main.cpp
	g++ -Wall -g -ansi -c main.cpp

calendar.o: main.cpp
	g++ -Wall -g -ansi -c calendar.cpp

appt.o: main.cpp
	g++ -Wall -g -ansi -c appt.cpp

day.o: main.cpp
	g++ -Wall -g -ansi -c day.cpp

time.o: main.cpp
	g++ -Wall -g -ansi -c time.cpp

clean:
	rm calendar.out main.o calendar.o appt.o day.o time.o

test:
	./Testing/DesignChecker.sh ./
