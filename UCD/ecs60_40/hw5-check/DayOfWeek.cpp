// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "DayOfWeek.h"

using namespace std;


void DayOfWeek::print() const
{
  char line[80], dayStr[3];
  strcpy(line, dayName);
  strcat(line, ", ");
  strcat(line, monthName);
  strcat(line, " ");
  
  if(day > 9)
  {
    dayStr[0] = day / 10 + '0';
    dayStr[1] = day % 10 + '0';
    dayStr[2] = '\0';
  } // if day > 9
  else // day < 10
  {
    dayStr[0] = day + '0';
    dayStr[1] = '\0';
  } // else day < 10

  strcat(line, dayStr);
  cout << left << setw(30) << line << right;
}  // print()


void DayOfWeek::read(int month, int day, int year)
{
  ifstream inf("DOW.dat", ios::binary);
  int dateNumber = (month - 1) * 31 + day - 1 + (year - 1990) * 372;
  inf.seekg(dateNumber * sizeof(DayOfWeek));
  inf.read((char*) this, sizeof(DayOfWeek));
  inf.close();
  
  
}  // read()

