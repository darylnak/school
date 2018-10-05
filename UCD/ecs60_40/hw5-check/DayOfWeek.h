#ifndef DAYOFWEEK_H
#define	DAYOFWEEK_H

class DayOfWeek 
{
  char monthName[10];
  int month;
  int day;
  int year;
  char dayName[10];
public:
  void read(int month, int day, int year);
  void print() const;
}; // class DayOfWeek

#endif	// DAYOFWEEK_H

