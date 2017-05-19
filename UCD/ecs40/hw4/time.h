#ifndef TIME_H
#define TIME_H

#include <stdbool.h>

class Time
{
private:

public:
  void read();
  void print() const;
  bool lessThan(const Time* time2) const;
  short hour;
  short minute;
}; // class Time

#endif
