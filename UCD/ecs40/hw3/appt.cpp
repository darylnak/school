#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "appt.h"

using namespace std;

void Appointment::destroy()
{
  delete [] subject;
  delete [] location;
} // destroy()

bool Appointment::equal(const char* currSubject) const
{
  if (strstr(subject, currSubject) != NULL) // find substring
    return true;

  return false;
} //equal()

bool Appointment::lessThan(const Appointment* arrAppt) const
{
  return startTime.lessThan(&arrAppt->startTime);
} //lessThan()

void Appointment::print() const
{
  startTime.print();
  endTime.print();
  cout << left << setw(13) << setfill(' ') << subject;
  cout << setfill(' ') << location;
  cout << right << endl;
} // print()

void Appointment::read()
{
  char* currLocation;
  char* currSubject;

  currSubject = strtok(NULL, "/,");
  subject = new char[(strlen(currSubject) + 1)];
  strcpy(subject, currSubject);

  startTime.read();
  endTime.read();

  currLocation = strtok(NULL, "/,");
  location = new char[(strlen(currLocation) + 1)];
  strcpy(location, currLocation);
} // read()
