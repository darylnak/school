// Author: Sean Davis

#ifndef TIME_H
#define	TIME_H

class Time
{
  short hour;
  short minute;
public:
  bool lessThan(const Time *time2) const;
  void print() const;
  void read();
}; // class Time


#endif	// TIME_H 

