#include "day.h"

#include <stdio.h>
#include <stdlib.h>

void create(Day* currDay, int month, int day, int year)
{
  currDay->month = month;
  currDay->day = day;
  currDay->year = year;
  currDay->apptCount = 0;
} // create()

void destroy(Day* day)
{
  for (int i = 0; i < day->apptCount; i++)
  {
    destroy( day->appts[i]);
    free( day->appts[i]);
  } // for every appointment
} // destroy()

bool equal(Day* day1, Day* day2)
{
  if (day1->month == day2->month && day1->day == day2->day
      && day1->year == day2->year) // if days equal, return true
    return true;

  return false; // days not equal
} // equal()

bool lessThan(Day* day1, Day* day2)
{
  if (day1->year < day2->year)
    return true; // day1 is less than because year

  if (day1->year == day2->year)
  {
    if (day1->month < day2->month)
      return true; // day1 less by month

    if (day1->month == day2->month)
    {
      if (day1->day < day2->day)
        return true; // day1 less by day
    } // else if months are same
  } // else if years are same

  return false; // day1 is not less
} // lessThan()

void print(Day* day)
{
  printf("Start End   Subject      Location\n");

  for (int i = 0; i < day->apptCount; i++) // for each appointment print
    print(day->appts[i]);
} // print()

void read(Day* currDay)
{
  Appointment* appt = (Appointment*) malloc(sizeof(Appointment));
  int i = 0;
  read(appt);

  for (i = 0; i < currDay->apptCount; i++)
  {
    if (lessThan(appt, currDay->appts[i]))
    {
      for (int j = currDay->apptCount; j > i; j--) // for each appointment
        currDay->appts[j] = currDay->appts[j - 1];

      currDay->appts[i] = appt;
      currDay->apptCount += 1;
      return;
    } // if appointment less than, insert appropriately
  } // for each appointment

  currDay->appts[i] = appt;
  currDay->apptCount += 1;
  return;
} // read()

void subjectSearch(Day* day, char* subject)
{
  for (int i = 0; i < day->apptCount; i++)
  {
    // check subject equality
    if (equal(day->appts[i], subject))
    {
      fprintf(stdout, "%2d/%2d/%d ", day->month, day->day, day->year);
      fflush(stdout);
      print(day->appts[i]);
    } // if subject are equal
  } // for each appointment
} // subjectSearch()
