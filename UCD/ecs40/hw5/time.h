// Author: Sean Davis

#ifndef TIME_H
#define	TIME_H

class Time
{
  short hour;
  short minute;
public:
  void getTime();
  bool operator<(const Time &time2) const;
  friend std::ostream& operator<<(std::ostream& os, const Time &time);
  void read();
}; // class Time


#endif	// TIME_H
