#ifndef TIME_H
#define TIME_H

#include <stdbool.h>

typedef struct Time_Struct {
  short hour;
  short minute;
} Time;

void read(Time* appt);
void print(Time* appt);
bool lessThan(Time* time1, Time* time2);

#endif
