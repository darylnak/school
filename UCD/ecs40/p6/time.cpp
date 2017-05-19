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


bool Time::operator< (const Time &time2) const
{
  return hour < time2.hour 
    || (hour == time2.hour && minute < time2.minute);
} // operator<


ostream& operator<< (ostream &os, const Time &time)
{
  os << setw(2) << setfill('0') <<  time.hour << ":" << setw(2) << time.minute 
    << ' ' << setfill(' ');
  
  return os;
} // operator<< ()


istream& operator>> (istream &is, Time &time)
{
  char line[80];
  
  is.getline(line, 80, ':');
  
  time.hour = atoi(line);
  is.getline(line, 80, ':');
  time.minute = atoi(line);
  is.getline(line, 80, ',');

  if(time.hour == 12 && strchr(line, 'A'))
    time.hour = 0;
  
  if(strchr(line, 'P') && time.hour < 12)
    time.hour += 12;
  
  return is;
} // operator>> 
