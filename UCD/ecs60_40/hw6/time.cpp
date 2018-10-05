// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "time.h"

using namespace std;

void Time::getTime()
{
  char colon;
  cin >> hour >> colon >> minute;

  while (hour < 0 || hour > 23 || minute < 0 || minute > 59)
  {
    cout << "Please try again (hh:mm) >> ";
    cin >> hour >> colon >> minute;

    if(hour < 0 || hour > 23)
      cout << "Hour must be between 0 and 23.\n";

    if(minute < 0 || minute > 59)
      cout << "Minute must be between 0 and 59.\n";
  } // while time is wrong
} // getTime()


bool Time::operator<(const Time &rhs) const
{
  return hour < rhs.hour
    || (hour == rhs.hour && minute < rhs.minute);
} // operator<()


ostream& operator<<(ostream& os, const Time &time)
{
  os << setw(2) << setfill('0') << time.hour << ":" << setw(2) << time.minute
     << ' ' << setfill(' ');

  return os;
} // operator<<()


std::istream& operator>>(std::istream &inf, Time &time)
{
  //char *ptr;
  char colon;
  char ampm[3];

  inf >> time.hour >> colon >> time.minute;
  inf.seekg(4, ios::cur);
  inf.getline(ampm, 3, ',');

  if(time.hour == 12 && strchr(ampm, 'A'))
    time.hour = 0;

  if(strchr(ampm, 'P') && time.hour < 12)
    time.hour += 12;

  return inf;
} // operator>>()
