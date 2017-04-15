#include "appt.h"

#include <stdio.h>
#include <stdlib.h>

bool lessThan(Appointment* appt)
{

  return true;
}

void print(Appointment* appt)
{

}

void read(Appointment* appt)
{
  appt->subject = strtok(NULL, "/,");
  printf("%s\n", appt->subject);

  read(&appt->startTime);
  read(&appt->endTime);
}
