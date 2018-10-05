// Author: Sean Davis

#ifndef TIME_H
#define	TIME_H

#include <iostream>
using namespace std;

class Time
{
  short hour;
  short minute;
public:
  void getTime();
  bool operator< (const Time &time2) const;
  friend ostream& operator<< (ostream &os, const Time &time);
  friend istream& operator>> (istream &is, Time &time);
}; // class Time


#endif	// TIME_H 

