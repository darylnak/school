#ifndef TIME_H
#define TIME_H

#include <stdbool.h>

class Time
{
public:
  short hour;
  short minute;

  void read();
  void print() const;
  bool lessThan(const Time* time2) const;
private:

}; // class Time

#endif
