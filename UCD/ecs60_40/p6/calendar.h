#ifndef CALENDAR_H
#define	CALENDAR_H

#include "day.h"
#include "vector.h"
#include "weeklyappt.h"

class Calendar
{
  Vector<Day> days;
public:
  Calendar();
  ~Calendar();
  void addAppointment();
  void createSeries(const WeeklyAppointment wap, int day, int month, int year);
  void dateSearch() const;
  void getDate(int *day, int *month, int *year) const;
  friend istream& operator>> (istream &is, Calendar &calendar);
  void subjectSearch() const;
};  // class Calendar

#endif	// CALENDAR_H 

