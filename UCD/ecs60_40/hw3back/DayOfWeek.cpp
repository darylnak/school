#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "DayOfWeek.h"

using namespace std;

void DayOfWeek::read(int currMonth, int currDay, int currYear)
{
  ifstream file("DOW.dat", ios::binary);

  // offset from 1/1/1990
  int offset = (372 * (currYear - 1990)) + (31 * (currMonth - 1)) + (currDay - 1);

  file.seekg(offset * sizeof(DayOfWeek));
  file.read((char*) this, sizeof(DayOfWeek));

} // read()

void DayOfWeek::print() const
{
  char strAppt[30];
  string day = to_string(this->day);

  strcat(strAppt, this->dayName);
  strcat(strAppt, ", ");
  strcat(strAppt, this->monthName);
  strcat(strAppt, " ");
  strcat(strAppt, day.c_str());

  cout << left << setw(30) << strAppt;
} // print()
