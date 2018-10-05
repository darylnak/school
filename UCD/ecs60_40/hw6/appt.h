#ifndef APPT_H
#define	APPT_H

#include "time.h"

using namespace std;

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
  static int count;
public:
  Appointment();
  Appointment(const Appointment &appt);
  ~Appointment();
  void addAppointment();
  bool operator==(const char *rhs) const;
  static int getCount();
  bool operator<(const Appointment &rhs) const;
  friend ostream& operator<<(ostream &os, const Appointment &appt);
  friend istream& operator>>(istream &inf, Appointment &appt);
}; // class Appointment

#endif	// APPT_H
