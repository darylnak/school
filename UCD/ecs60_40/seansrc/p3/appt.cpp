// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <string.h>
#include "appt.h"
#include "time.h"

using namespace std;


void Appointment::destroy()
{
  delete [] subject;
  delete [] location;
}  // destroy()


bool Appointment::equal(const char *subject2)const
{
  return strstr(subject, subject2) != NULL;
}  // equal()


bool Appointment::lessThan(const Appointment *appointment2) const
{
  return startTime.lessThan(&appointment2->startTime); 
}  // lessThan()


void Appointment::print() const
{
  startTime.print();
  endTime.print();
  cout << left << setw(13) << subject << location << right << endl;
} // print()


void Appointment::read()
{
  char *ptr;
  ptr = strtok(NULL, ",");
  subject = new char[strlen(ptr) + 1];
  strcpy(subject, ptr);
  startTime.read();
  endTime.read();
  ptr = strtok(NULL, "\n");
  location = new char[strlen(ptr) + 1];
  strcpy(location, ptr);
} // read()

