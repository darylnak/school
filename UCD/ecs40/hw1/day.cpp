#include "day.h"

#include <stdio.h>

void create(Day* currDay, int month, int day, int year)
{
  currDay->month = month;
  currDay->day = day;
  currDay->year = year;
  currDay->apptCount = 0;
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
  for (int i = 0; i < 8; i++) {
    print(currDay->appts[i]);
  }
}

void read(Day* currDay)
{
  
}
