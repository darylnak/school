#ifndef APPT_H
#define	APPT_H

#include <iostream>
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
  virtual ~Appointment();
  void addAppointment();
  virtual Appointment* clone();
  bool operator== (const char *subject) const;
  static int getCount();
  virtual istream& read(istream &is);
  bool operator< (const Appointment &appointment2) const;
  friend ostream& operator<< (ostream &os, const Appointment &appointment);
  virtual ostream& write(ostream&) const;
}; // class Appointment

#endif	// APPT_H
