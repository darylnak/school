#ifndef APPT_H
#define APPT_H

#include <stdbool.h>
#include <string.h>

#include "time.h"

typedef struct Appointment_Struct {
  Time startTime;
  Time endTime;
  char* subject;
  char* location;
} Appointment;

void read(Appointment* appt);
void print(Appointment* appt);
bool lessThan(Appointment* appt);
void destroy(Appointment* appt);

#endif
