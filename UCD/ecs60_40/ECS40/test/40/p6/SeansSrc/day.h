#ifndef DAY_H
#define	DAY_H
// Author: Sean Davis

#include <iostream>
#include "linkedlist.h"
#include "appt.h"
#include "weeklyappt.h"
using namespace std;

class Day
{
  short day;
  short month;
  short year;
  LinkedList<Appointment*> appts;
public:
  Day();
  Day(int day1, int month, int year);
  void addAppointment();
  bool operator== (const Day &day2) const;
  bool operator< (const Day &day2) const;
  Day& operator= (const Day &day);
  Day& operator+= (const WeeklyAppointment &weeklyAppointment);
  friend ostream& operator<< (ostream &os, const Day &day); 
  friend const Appointment* operator>> (istream &is, Day &day); 
  
  void subjectSearch(const char *subject) const;
}; // class Day




#endif	// DAY_H 
