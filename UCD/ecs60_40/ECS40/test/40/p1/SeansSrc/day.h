#ifndef DAY_H
#define	DAY_H
// Author: Sean Davis
#include "appt.h"

typedef struct
{
  short day;
  short month;
  short year;
  Appointment *appts[8];
  short apptCount;
} Day;

void create(Day *day, int day1, int month, int year);
void destroy(Day *day);
bool equal(Day *day1, Day *day2);
bool lessThan(Day *day1, Day *day2);
void print(Day *day);
void read(Day *day);
void subjectSearch(Day *day, char *subject);




#endif	// DAY_H 

