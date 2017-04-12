CC = g++

calendar: main.o calendar.o appt.o day.o time.o
	$(CC) main.o calendar.o appt.o day.o time.o -g -ansi -Wall -o calendar.out

%.o: %.c
	$(CC) -Wall -c $<

clean:
	rm main.o calendar.o appt.o day.o time.o
