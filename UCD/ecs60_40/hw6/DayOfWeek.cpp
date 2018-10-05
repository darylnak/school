// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "DayOfWeek.h"

using namespace std;

DayOfWeek::DayOfWeek(int currMonth, int currDay, int currYear) :
month(currMonth), day(currDay), year(currYear)
{

} // DayOfWeek()

std::ostream& operator<<(std::ostream &os, const DayOfWeek &dow)
{
  char line[80], dayStr[3];
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

  strcat(line, dayStr);
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
