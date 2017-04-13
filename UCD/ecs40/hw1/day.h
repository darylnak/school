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

void create(Day* day);
void equal(Day* day);
bool lessThan(Day* day);
void read(Day* day);
void print(Day* day);
void subjectSearch(Day* day);
void destroy(Day* day);

#endif
