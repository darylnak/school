#ifndef DAY_H
#define DAY_H

#include <stdbool.h>

#include "appt.h"

typedef struct Day_Struct{
  short month;
  short day;
  short year;
  short apptCount;
  Appointment* appts[8];
} Day;

void create(Day* currDay, int month, int day, int year);
bool equal(Day* day1, Day* day2);
bool lessThan(Day* day1, Day* day2);
void read(Day* currDay);
void print(Day* day);
void subjectSearch(Day* day);
void destroy(Day* day);

#endif
