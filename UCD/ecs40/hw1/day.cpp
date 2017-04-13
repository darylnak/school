#include "day.h"

#include <stdio.h>

void create(Day* currDay, int month, int day, int year) {
  currDay->month = month;
  currDay->day = day;
  currDay->year = year;
}
