#ifndef DAY_H
#define	DAY_H

#include "appt.h"
#include "linkedlist.h"

using namespace std;

class Day
{
private:
  short day;
  short month;
  short year;
  LinkedList appts;
  short apptCount;

public:
  Day();
  Day(int day1, int month, int year);
  void addAppointment();
  bool operator==(const Day &rhs) const;
  bool operator<(const Day &rhs) const;
  Day& operator= (const Day &day);
  friend ostream& operator<< (ostream &os, const Day &rhs);
  friend istream& operator>> (istream &inf, Day &day);
  void subjectSearch(const char *subject) const;
}; // class Day

#endif	// DAY_H
