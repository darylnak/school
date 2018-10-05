// Author: Sean Davis

#include <stdio.h>
#include <stdlib.h>

#include "day.h"
#include "appt.h"

void create(Day *day, int day1, int month, int year)
{
  day->day = day1;
  day->month = month;
  day->year = year;
  day->apptCount = 0;
}  // create()


void destroy(Day *day)
{
  for(int i = 0; i < day->apptCount; i++)
  {
    destroy(day->appts[i]);
    free(day->appts[i]);
  } // for each appointment
}  // destroy()


bool equal(Day *day1, Day *day2)
{
  return day1->day == day2->day && day1->month == day2->month 
    && day1->year == day2->year;
} // equal()


bool lessThan(Day *day1, Day *day2)
{
  return (day1->year < day2->year)
    || (day1->year == day2->year && day1->month < day2->month)
    || (day1->year == day2->year && day1->month == day2->month 
      && day1->day < day2->day); 
} // lessThan()


void print(Day *day)
{
  printf("Start End   Subject      Location\n");
  
  for(int i = 0; i < day->apptCount; i++)
    print(day->appts[i]);
  
  printf("\n");
} // print90

void read(Day *day)
{
  int pos;
  Appointment *appointment = (Appointment*) malloc(sizeof(Appointment));
  read(appointment);
  
  for(pos = day->apptCount - 1; 
    pos >= 0 && lessThan(appointment, day->appts[pos]); pos--)
      day->appts[pos + 1] = day->appts[pos];
  
  day->appts[pos + 1] = appointment;
  day->apptCount++;
} // read()


void subjectSearch(Day *day, char *subject)
{
  for(int i = 0; i < day->apptCount; i++)
    if(equal(day->appts[i], subject))
    {
      printf("%2d/%2d/%4d ", day->month, day->day, day->year);
      print(day->appts[i]);
    } // if appointment has the subject
      
} // subjectSearch()
