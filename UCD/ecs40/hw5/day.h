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
  Day();
  Day(int day1, int month, int year);
  ~Day();
  void addAppointment();
  bool operator==(const Day &rhs) const;
  void insert(Appointment *appt);
  bool operator<(const Day &rhs) const;
  Day& operator= (const Day &day);
  friend std::ostream& operator<<(std::ostream &os, const Day &rhs);
  void read();
  void subjectSearch(const char *subject) const;
}; // class Day




#endif	// DAY_H
