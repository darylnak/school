// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "DayOfWeek.h"

using namespace std;


DayOfWeek::DayOfWeek(int month1, int day1, int year1) : month(month1), 
  day(day1), year(year1)
{
}  // DayOfWeek()


ostream& operator<< (ostream &os, const DayOfWeek &dayOfWeek)
{
  char line[80], dayStr[3];
  strcpy(line, dayOfWeek.dayName);
  strcat(line, ", ");
  strcat(line, dayOfWeek.monthName);
  strcat(line, " ");
  
  if(dayOfWeek.day > 9)
  {
    dayStr[0] = dayOfWeek.day / 10 + '0';
    dayStr[1] = dayOfWeek.day % 10 + '0';
    dayStr[2] = '\0';
  } // if day > 9
  else // day < 10
  {
    dayStr[0] = dayOfWeek.day + '0';
    dayStr[1] = '\0';
  } // else day < 10

  strcat(line, dayStr);
  os << left << setw(30) << line << right;
  return os;
}  // operator<<()


istream& operator>> (istream &is, DayOfWeek &day) 
{
  int dateNumber = (day.month - 1) * 31 + day.day - 1 + (day.year - 1990) * 372;
  is.seekg(dateNumber * sizeof(DayOfWeek));
  is.read((char*) &day, sizeof(DayOfWeek));
  return is;
}  // operator>>

