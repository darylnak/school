// Author: Sean Davis

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"

bool lessThan(Time *time1, Time *time2)
{
  return time1->hour < time2->hour 
    || (time1->hour == time2->hour && time1->minute < time2->minute);
} // lessThan()


void print(Time *time)
{
  printf("%02d:%02d ", time->hour, time->minute);
} // print()


void read(Time *time)
{
  char *ptr;
  
  time->hour = atoi(strtok(NULL, ":"));
  time->minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");
  
  if(strchr(ptr, 'P'))
    time->hour += 12;
  
} // read()
