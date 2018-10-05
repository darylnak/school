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


 bool DayOfWeek::operator== (char initial) const
 {
   switch(initial)
   {
     case 'M' : return strcmp(dayName, "Monday") == 0;
     case 'T' : return strcmp(dayName, "Tuesday") == 0;
     case 'W' : return strcmp(dayName, "Wednesday") == 0;
     case 'R' : return strcmp(dayName, "Thursday") == 0;
     case 'F' : return strcmp(dayName, "Friday") == 0;
     case 'S' : return strcmp(dayName, "Saturday") == 0;
     case 'U' : return strcmp(dayName, "Sunday") == 0;
   }  // switch on initial
   
   return false;
 }  // operator==

ostream& operator<< (ostream &os, const DayOfWeek &dayOfWeek)
{
  char line[80], dayStr[3], yearStr[5];
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
  strcat(line, ", ");
  yearStr[0] = dayOfWeek.year / 1000 + '0';
  yearStr[1] = (dayOfWeek.year % 1000) / 100 + '0';
  yearStr[2] = (dayOfWeek.year % 100) / 10 + '0';
  yearStr[3] = dayOfWeek.year % 10 + '0';
  yearStr[4] = '\0';
  strcat(line, yearStr);
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

