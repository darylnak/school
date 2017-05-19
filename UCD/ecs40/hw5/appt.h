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
  static int count;
public:
  Appointment();
  Appointment(const Appointment &appt);
  ~Appointment();
  void addAppointment();
  bool operator==(const char *rhs) const;
  static int getCount();
  bool operator<(const Appointment &rhs) const;
  friend std::ostream& operator<<(std::ostream &os, const Appointment &appt);
  void read();


}; // class Appoiintmen
#endif	// APPT_H
