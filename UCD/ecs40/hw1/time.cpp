#include "appt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(Time* appt)
{

}

void read(Time* appt)
{
  int hour = atoi(strtok(NULL, "/,:"));
  int minute = atoi(strtok(NULL, "/,:"));
  printf("Hour: %d\n", hour);
  printf("Minute: %d\n", minute);
}
