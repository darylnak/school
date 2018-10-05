#ifndef DAY_H
#define	DAY_H

#include "appt.h"

class Day
{
  short day;
  short month;
  short year;
  Appointment *appts[8];
  short apptCount;
public:
  Day();
  Day(int day1, int month1, int year1);
  ~Day();
  Day& operator=(const Day &rhs);
  void addRead();
  void insertAppt(Day* dayTemp);
  bool isDuplicate(const Day* dayTemp) const;
  bool equal(const Day *day2) const;
  bool lessThan(const Day *day2) const;
  void print() const;
  void read();
  void subjectSearch(const char *subject) const;
}; // class Day

#endif	// DAY_H
