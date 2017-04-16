// 1
// Author: Sean Davis

#include <fstream>
#include <iostream>
#include <string.h>
#include "dayofweek.h"

using namespace std;

DayOfWeek::DayOfWeek(int mo, int d): month(mo), day(d)
{
} // DayOfWeek()


void DayOfWeek::print() const
{
  int len = strlen(dayName) + strlen(monthName);

  if (day > 9)
    len++;

  cout << dayName << ", " <<  monthName << " " << day;

  for(int i = len; i < 27; i++)
    cout << " ";

} // print()

void DayOfWeek::read()
{
  ifstream inf("DOW.dat", ios::binary);
  inf.seekg(sizeof(DayOfWeek) * ((month - 1) * 31 + day - 1));
  inf.read((char*) this, sizeof(DayOfWeek));
} // read()






