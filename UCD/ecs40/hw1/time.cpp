#include "appt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(Time* appt)
{

}

void read(Time* time)
{
  int hour = atoi(strtok(NULL, "/,:"));
  int minute = atoi(strtok(NULL, "/,:"));
  char* ampm = strchr(strtok(NULL, "/,:"), ' ');

  if (strcmp(ampm," am") == 0)
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

bool lessThan(Time* time1, Time* time2)
{

  return true;
}
