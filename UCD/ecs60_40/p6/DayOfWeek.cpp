// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "DayOfWeek.h"
#include <cctype>

using namespace std;

DayOfWeek::DayOfWeek(int currMonth, int currDay, int currYear) :
month(currMonth), day(currDay), year(currYear)
{
} // DayOfWeek()


bool DayOfWeek::operator==(char c)
{
  if (c == 'M' && !strcmp(dayName, "Monday"))
    return true;

  if (c == 'T' && !strcmp(dayName, "Tuesday"))
    return true;

  if (c == 'W' && !strcmp(dayName, "Wednesday"))
    return true;

  if (c == 'R' && !strcmp(dayName, "Thursday"))
    return true;

  if (c == 'F' && !strcmp(dayName, "Friday"))
    return true;

  if (c == 'S' && !strcmp(dayName, "Saturday"))
    return true;

  if (c == 'U' && !strcmp(dayName, "Sunday"))
    return true;

  return false;
} // operator==()


std::ostream& operator<<(std::ostream &os, const DayOfWeek &dow)
{
  char line[80], dayStr[3];
  ostringstream convert;
  string yearStr;
  strcpy(line, dow.dayName);
  strcat(line, ", ");
  strcat(line, dow.monthName);
  strcat(line, " ");

  if(dow.day > 9)
  {
    dayStr[0] = dow.day / 10 + '0';
    dayStr[1] = dow.day % 10 + '0';
    dayStr[2] = '\0';
  } // if day > 9
  else // day < 10
  {
    dayStr[0] = dow.day + '0';
    dayStr[1] = '\0';
  } // else day < 10

  convert << dow.year;
  yearStr = convert.str();

  strcat(line, dayStr);
  strcat(line, ", ");
  strcat(line, yearStr.c_str());

  os << left << setw(30) << line << right;

  return os;
}  // operator<<()


std::istream& operator>>(std::istream &inf, DayOfWeek &dow)
{
  int dateNumber = (dow.month - 1) * 31 + dow.day - 1 + (dow.year - 1990) * 372;
  inf.seekg(dateNumber * sizeof(DayOfWeek));
  inf.read((char*) &dow, sizeof(DayOfWeek));

  return inf;
}  // operator>>()
