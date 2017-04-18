#include "appt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool lessThan(Time* time1, Time* time2)
{
  if (time2->hour == 24 && time1->hour < 24) // if hour is less
    return true;

  if (time1->hour < time2->hour) // else if hour is less
    return true;

  if (time1->hour == time2->hour) // same hours
  {
    if (time1->minute < time2->minute) // time1 minutes < time2 minutes
      return true;
    else // time1 minutes not < time2 minutes
      return false;
  } // if hours are the same

  return false;
} // lessThan()

void print(Time* appt)
{
  fprintf(stdout, "%02d", appt->hour);
  fflush(stdout);
  fprintf(stdout, ":");
  fflush(stdout);
  fprintf(stdout, "%02d ", appt->minute);
  fflush(stdout);
} // print()

void read(Time* time)
{
  int hour = atoi(strtok(NULL, "/,:"));
  int minute = atoi(strtok(NULL, "/,:"));
  char* ampm = strchr(strtok(NULL, "/,:"), ' ');

  if (strcmp(ampm, " AM") == 0) // check for AM time
  {
    if (hour == 12) // midnight
    {
      if (minute == 0) // minute(s) are 0
      {
        time->hour = 24;
        time->minute = 0;
        return;
      } // if minute(s) are zero
      else // minute(0) are not 0
      {
        time->hour = 0;
        time->minute = minute;
        return;
      } // else minute(s) are not zero
    } // if midnight
    else // not midnight
    {
      time->hour = hour;
      time->minute = minute;
      return;
    } //  else just return hours and minute(s)
  } // if morning
  else // In PM
  {
    time->hour = hour + 12;
    time->minute = minute;
    return;
  } // else time in PM
} // read()
