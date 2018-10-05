#ifndef APPT_H
#define APPT_H

#include <stdbool.h>
#include <string.h>

#include "time.h"

typedef struct
{
  Time startTime;
  Time endTime;
  char* subject;
  char* location;
} Appointment;

bool equal(Appointment* appt, char* subject);
void read(Appointment* appt);
void print(Appointment* appt);
bool lessThan(Appointment* appt, Appointment* arrAppt);
void destroy(Appointment* appt);

#endif
