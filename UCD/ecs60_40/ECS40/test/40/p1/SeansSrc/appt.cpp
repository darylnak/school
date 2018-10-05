// Author: Sean Davis

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "appt.h"
#include "time.h"


void destroy(Appointment *appointment)
{
  free(appointment->subject);
  free(appointment->location);
}  // destroy()


bool equal(Appointment *appointment, char *subject)
{
  return strstr(appointment->subject, subject) != NULL;
}  // equal()


bool lessThan(Appointment *appointment1, Appointment *appointment2)
{
  return lessThan(&appointment1->startTime, &appointment2->startTime); 
}  // lessThan()


void print(Appointment *appointment)
{
  print(&appointment->startTime);
  print(&appointment->endTime);
  printf("%-13s%s\n", appointment->subject, appointment->location);
} // print()


void read(Appointment *appointment)
{
  char *ptr;
  ptr = strtok(NULL, ",");
  appointment->subject = (char*) malloc(strlen(ptr) + 1);
  strcpy(appointment->subject, ptr);
  read(&appointment->startTime);
  read(&appointment->endTime);
  ptr = strtok(NULL, "\n");
  appointment->location = (char*) malloc(strlen(ptr) + 1);
  strcpy(appointment->location, ptr);
} // read()

