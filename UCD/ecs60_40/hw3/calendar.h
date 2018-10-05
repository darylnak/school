#ifndef CALENDAR_H
#define	CALENDAR_H

#include "day.h"

class Calendar
{
  Day *days;
  int size;
  int count;
public:
  Calendar();
  ~Calendar();
  void addAppointment();
  void dateSearch() const;
  void rejectOrInsert(Day* dayTemp);
  void getDate(int *day, int *month, int *year) const;
  void readFile();
  void resize();
  void subjectSearch() const;
};  // class Calendar

#endif	// CALENDAR_H
