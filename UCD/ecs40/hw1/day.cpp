#include "day.h"

#include <stdio.h>
#include <stdlib.h>

void create(Day* currDay, int month, int day, int year)
{
  currDay->month = month;
  currDay->day = day;
  currDay->year = year;
  currDay->apptCount = 0;
}

void destroy(Day* currDay)
{
  for (int i = 0; i < currDay->apptCount; i++)
  {
    destroy(currDay->appts[i]);
    free(currDay->appts[i]);
  }
}

bool equal(Day* day1, Day* day2)
{
  if (day1->month == day2->month && day1->day == day2->day &&
      day1->year == day2->year)
  {
    return true;
  }
  return false;
}

bool lessThan(Day* day1, Day* day2)
{
  if (day1->year < day2->year)
    return true;
  else if (day1->year == day2->year)
  {
    if (day1->month < day2->month)
      return true;
    else if (day1->month == day2->month)
    {
      if (day1->day < day2->day)
        return true;
    }
  }
  return false;
}

void print(Day* currDay)
{
  printf("Start End   Subject      Location\n");
  for (int i = 0; i < currDay->apptCount; i++) {
    print(currDay->appts[i]);
  }
}

void read(Day* currDay)
{
  Appointment* appt = (Appointment*) malloc(sizeof(Appointment));
  int i = 0;
  read(appt);

  for (i = 0; i < currDay->apptCount; i++)
  {
    if (lessThan(appt, currDay->appts[i]))
    {
      for (int j = currDay->apptCount; j > i; j--)
        currDay->appts[j] = currDay->appts[j - 1];
      currDay->appts[i] = appt;
      currDay->apptCount += 1;
      return;
    }
  }
  currDay->appts[i] = appt;
  currDay->apptCount += 1;

  return;
}

void subjectSearch(Day* day, char* subject)
{
  for (int i = 0; i < day->apptCount; i++)
  {
    if (equal(day->appts[i], subject))
    {
      fprintf(stdout, "%2d/%2d/%d ", day->month, day->day, day->year);
      fflush(stdout);
      print(day->appts[i]);
    }
  }
}
