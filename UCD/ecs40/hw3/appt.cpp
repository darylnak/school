// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <string.h>
#include "appt.h"
#include "time.h"

using namespace std;

Appointment::Appointment() : subject(NULL), location(NULL)
{ } // Appointment default contructor

Appointment::Appointment(const Appointment &appt) :
startTime(appt.startTime), endTime(appt.endTime)
{
  subject = new char[strlen(appt.subject) + 1];
  location = new char[strlen(appt.location) + 1];

  strcpy(subject, appt.subject);
  strcpy(location, appt.location);
} // Appointment copy constructor

Appointment::~Appointment()
{
  delete [] subject;
  delete [] location;
}  // Appointment destructor


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
