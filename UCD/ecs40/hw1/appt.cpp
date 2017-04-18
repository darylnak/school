#include "appt.h"

#include <stdio.h>
#include <stdlib.h>

void destroy(Appointment* appt)
{
  free(appt->subject);
  free(appt->location);
}

bool equal(Appointment* appt, char* subject)
{
  if (strstr(appt->subject, subject) != NULL)
    return true;
  return false;
}

bool lessThan(Appointment* appt, Appointment* arrAppt)
{
  return lessThan(&appt->startTime, &arrAppt->startTime);
}

void print(Appointment* appt)
{
  print(&appt->startTime);
  print(&appt->endTime);
  printf("%-13s", appt->subject);
  fflush(stdout);
  printf("%s", appt->location);
  fflush(stdout);
  printf("\n");
}

void read(Appointment* appt)
{
  char* location;
  char* subject;

  subject = strtok(NULL, "/,");
  appt->subject = (char*) malloc(sizeof(char) * strlen(subject));
  strcpy(appt->subject, subject);

  read(&appt->startTime);
  read(&appt->endTime);

  location = strtok(NULL, "/,");
  location[strlen(location) - 1] = '\0';
  appt->location = (char*) malloc(sizeof(char) * strlen(location));
  strcpy(appt->location, location);
}
