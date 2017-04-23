calendar.out: main.o calendar.o appt.o day.o time.o
	g++ main.o calendar.o appt.o day.o time.o -g -Wall -o calendar.out

main.o: main.cpp
	g++ -Wall -g -ansi -c main.cpp

calendar.o: calendar.cpp
	g++ -Wall -g -ansi -c calendar.cpp

appt.o: appt.cpp
	g++ -Wall -g -ansi -c appt.cpp

day.o: day.cpp
	g++ -Wall -g -ansi -c day.cpp

time.o: time.cpp
	g++ -Wall -g -ansi -c time.cpp

clean:
	rm calendar.out main.o calendar.o appt.o day.o time.o

test:
	./Testing/DesignChecker.sh ./
