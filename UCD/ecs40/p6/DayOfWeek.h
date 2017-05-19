#ifndef DAYOFWEEK_H
#define	DAYOFWEEK_H

using namespace std;

class DayOfWeek
{
  char monthName[10];
  int month;
  int day;
  int year;
  char dayName[10];
public:
  DayOfWeek(int currMonth, int currDay, int currYear);
  bool operator==(char c);
  friend ostream& operator<<(ostream &os, const DayOfWeek &dow);
  friend istream& operator>>(istream &ins, DayOfWeek &dow);
}; // class DayOfWeek

#endif	// DAYOFWEEK_H
