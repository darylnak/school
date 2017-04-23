#ifndef APPT_H
#define APPT_H

#include <stdbool.h>
#include <string.h>

#include "time.h"

class Appointment
{
public:
  Time startTime;
  Time endTime;
  char* subject;
  char* location;

  void destroy();
  bool equal(const char* currSubject) const;
  bool lessThan(const Appointment* arrAppt) const;
  void print() const;
  void read();
private:

}; // Appointment

#endif
