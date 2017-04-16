// Author: Sean Davis

#ifndef dayH
#define dayH

#include <iostream>
#include "appointment.h"
using namespace std;

class Day
{
  short day;
  short month;
  Appointment *appts[8];
  short apptCount;
public:
  Day();
  ~Day();
  int compareDate(short mo, short d) const;
   void print() const;
  void printAppts() const;
  void printSubject(const char *s, bool &found) const;
  void read();
  void reset(short mo, short d);
  Day& operator= (const Day &d);
 
}; // class Day

#endif
