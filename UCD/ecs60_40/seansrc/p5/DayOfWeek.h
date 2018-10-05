#ifndef DAYOFWEEK_H
#define	DAYOFWEEK_H

#include <iostream>
using namespace std;

class DayOfWeek 
{
  char monthName[10];
  int month;
  int day;
  int year;
  char dayName[10];
public:
  DayOfWeek(int mon, int day1, int year1);
  friend istream& operator>> (istream &is, DayOfWeek &day); 
  friend ostream& operator<< (ostream &os, const DayOfWeek &day); 
}; // class DayOfWeek

#endif	// DAYOFWEEK_H

