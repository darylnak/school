#ifndef APPT_H
#define APPT_H

#include <stdbool.h>
#include <string.h>

#include "time.h"

class Appointment
{
private:

public:
  void destroy();
  bool equal(const char* currSubject) const;
  bool lessThan(const Appointment* arrAppt) const;
  void print() const;
  void read();
  Time startTime;
  Time endTime;
  char* subject;
  char* location;
}; // Appointment

#endif
