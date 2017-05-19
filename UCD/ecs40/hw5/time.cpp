// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
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


void Time::read()
{
  char *ptr;

  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");

  if(hour == 12 && strchr(ptr, 'A'))
    hour = 0;

  if(strchr(ptr, 'P') && hour < 12)
    hour += 12;

} // read()
