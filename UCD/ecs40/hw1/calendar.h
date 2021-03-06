#ifndef CALENDAR_H
#define CALENDAR_H

#include "day.h"

typedef struct
{
  Day* days;
  int size;
  int count;
} Calendar;

void shift(Calendar* calendar, Day* dayTemp, int i);
void largest(Calendar* calendar, Day* dayTemp, int i);
void create(Calendar* calendar);
void readFile(Calendar* calendar);
void resize(Calendar* calendar);
void dateSearch(Calendar* calendar);
void getDate(int* const month, int* const day, int* const year);
void subjectSearch(Calendar* calendar);
void destroy(Calendar* calendar);

#endif
