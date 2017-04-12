#ifndef CALENDAR_H
#define CALENDAR_H

#include "day.h"

typedef struct Calendar_Struct {
  Day* days;
  int size;
  int count;
} Calendar;

void create(Calendar* calendar);
void readFile(Calendar* calendar);
void resize(Calendar* calendar);
void dateSearch(Calendar* calendar);
void getDate(Calendar* calendar);
void subjectSearch(Calendar* calendar);
void destroy(Calendar* calendar);

#endif
