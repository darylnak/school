#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "DayOfWeek.h"

using namespace std;

void DayOfWeek::read(int currMonth, int currDay, int currYear) const
{
  ifstream file("DOW.dat", ios::binary);

  // offset from 1/1/1990
  int offset = (372 * (currYear - 1990)) +
               (31 * (currMonth - 1)) +
               (currDay - 1);

  file.seekg(offset * sizeof(DayOfWeek));
  file.read((char*) this, sizeof(DayOfWeek));

} // read()

void DayOfWeek::print() const
{
  char strAppt[30] = "\0";
  stringstream day;
  string currDay;
  day << this->day;
  currDay = day.str();

  strcat(strAppt, this->dayName);
  strcat(strAppt, ", ");
  strcat(strAppt, this->monthName);
  strcat(strAppt, " ");
  strcat(strAppt, currDay.c_str());

  cout << left << setw(30) << strAppt << right;
} // print()
