#ifndef CALENDAR_H
#define CALENDAR_H

#include <fstream>

#include "day.h"

class Calendar
{
public:
  Calendar();
  void shift(Day* dayTemp, int i);
  void largest(const Day* dayTemp, int i);
  void readFile();
  void resize();
  void dateSearch() const;
  void getDate(int* month, int* day, int* year) const;
  void subjectSearch() const;
  void destroy();
  
private:
  Day* days;
  int size;
  int count;
}; // Calendar

#endif
