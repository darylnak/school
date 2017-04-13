CC = g++

calendar: main.o calendar.o appt.o day.o time.o
	$(CC) main.o calendar.o appt.o day.o time.o -g -Wall -o calendar.out

%.o: %.cpp
	$(CC) -Wall -g -ansi -c $<

clean:
	rm main.o calendar.o appt.o day.o time.o
