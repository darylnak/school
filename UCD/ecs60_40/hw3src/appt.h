#ifndef APPT_H
#define	APPT_H
// Author: Sean Davis
#include "time.h"

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
public:
  void destroy();
  bool equal(const char *subject) const;
  bool lessThan(const Appointment *appointment2) const;
  void print() const;
  void read();

}; // class Appoiintmen
#endif	// APPT_H 

