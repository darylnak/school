// 1
// Author: Sean Davis
#ifndef dayofweekH
#define dayofweekH

class DayOfWeek
{
  char monthName[10];
  int month;
  int day;
  char dayName[10];
public:
  DayOfWeek(int mo, int d);
  void print() const;
  void read();
}; // class DayOfWeek
//---------------------------------------------------------------------------
#endif

