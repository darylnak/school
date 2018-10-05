#ifndef APPT_H
#define	APPT_H

#include "time.h"

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;

public:
  static int count;

  Appointment();
  Appointment(const Appointment &appt);
  ~Appointment();
  void addRead();
  bool equal(const char *subject) const;
  static void getCount();
  bool isDuplicate(const Appointment* appt) const;
  bool lessThan(const Appointment *appointment2) const;
  void print() const;
  void read();

}; // class Appointment
#endif	// APPT_H
