#include "appt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool lessThan(Time* time1, Time* time2)
{
  if (time2->hour == 24 && time1->hour < 24)
  {
    return true;
  }
  else if (time1->hour < time2->hour)
  {
    return true;
  }
  else if (time1->hour == time2->hour)
  {
    return (time1->minute < time2->minute) ? true : false;
  }

  return false;
}

void print(Time* appt)
{
  fprintf(stdout, "%02d", appt->hour);
  fflush(stdout);
  fprintf(stdout, ":");
  fflush(stdout);
  fprintf(stdout, "%02d ", appt->minute);
  fflush(stdout);
}

void read(Time* time)
{
  int hour = atoi(strtok(NULL, "/,:"));
  int minute = atoi(strtok(NULL, "/,:"));
  char* ampm = strchr(strtok(NULL, "/,:"), ' ');

  if (strcmp(ampm," AM") == 0)
  {
    if (hour == 12)
    {
      if (minute == 0)
      {
        time->hour = 24;
        time->minute = 0;
        return;
      }
      else{
        time->hour = 0;
        time->minute = minute;
        return;
      }
    }
    else
    {
      time->hour = hour;
      time->minute = minute;
      return;
    }
  }
  else
  {
    time->hour = hour + 12;
    time->minute = minute;
    return;
  }
}
