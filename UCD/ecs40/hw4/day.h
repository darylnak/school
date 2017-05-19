#ifndef DAY_H
#define DAY_H

#include <stdbool.h>

#include "appt.h"

class Day
{
private:

public:
  Day();
  Day(int currMonth, int currDay, int currYear);
  bool equal(const Day* day2) const;
  bool lessThan(const Day* day2) const;
  void read();
  void print() const;
  void subjectSearch(const char* subject) const;
  void destroy();
  short month;
  short day;
  short year;
  short apptCount;
  Appointment* appts[8];
}; // class Day

#endif
