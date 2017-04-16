// 1
#ifndef appointmentH
#define appointmentH

#include "time.h"

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
public:
  Appointment();
  ~Appointment();
  void read();
  void print() const;
  bool compareSubject(const char *s) const;
  Appointment& operator= (const Appointment &a);
}; // class Appointment

#endif
