#ifndef DAY_H
#define	DAY_H
// Author: Sean Davis
#include "appt.h"

class Day
{
  short day;
  short month;
  short year;
  Appointment *appts[8];
  short apptCount;
public:
  void create(int day1, int month, int year);
  void destroy();
  bool equal(const Day *day2) const;
  bool lessThan(const Day *day2) const;
  void print() const;
  void read();
  void subjectSearch(const char *subject) const;
}; // class Day




#endif	// DAY_H 

