#ifndef APPT_H
#define	APPT_H
// Author: Sean Davis
#include "time.h"

typedef struct
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
}  Appointment;

void destroy(Appointment *appointment);
bool equal(Appointment *appointment, char *subject);
bool lessThan(Appointment *appointment1, Appointment *appointment2);
void print(Appointment *appointment);
void read(Appointment *appointment);
#endif	// APPT_H 

