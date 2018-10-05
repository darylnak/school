#ifndef CALENDAR_H
#define	CALENDAR_H
// Author: Sean Davis

#include "day.h"

typedef struct
{
  Day *days;
  int size;
  int count;
} Calendar;

void create(Calendar *calendar);
void dateSearch(Calendar *calendar);
void destroy(Calendar *calendar);
void getDate(int *day, int *month, int *year);
void readFile(Calendar *calendar);
void resize(Calendar *calendar);
void subjectSearch(Calendar *calendar);
#endif	// CALENDAR_H 

