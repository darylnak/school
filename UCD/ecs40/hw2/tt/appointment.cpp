// 1
// Author: Sean Davis

#include <cstring>
#include <iostream>
#include <iomanip>
#include "appointment.h"

using namespace std;

Appointment::Appointment() : subject(NULL), location(NULL)
{
}  // Appointment()


Appointment::~Appointment()
{
  if(subject)
    delete [] subject;

  if(location)
    delete [] location;
} // ~Appointment()


bool Appointment::compareSubject(const char *s) const
{
  return strcmp(subject, s) == 0;
}  // compareSubject()


void Appointment::read()
{
  char *ptr;

  ptr = strtok(NULL, ",");
  subject = new char[strlen(ptr) + 1];
  strcpy(subject, ptr);
  startTime.read();
  endTime.read();
  ptr = strtok(NULL, ",");
  location = new char[strlen(ptr) + 1];
  strcpy(location, ptr);
} // read()


void Appointment::print() const
{
  startTime.print();
  endTime.print();
  cout << setw(15) << left << subject << " " << location << endl;
} // print()


Appointment& Appointment::operator= (const Appointment &rhs)
{
  if(this == &rhs)
    return *this;

  startTime = rhs.startTime;
  endTime = rhs.endTime;
  
  if(subject)
  {
    delete [] subject;
    subject = NULL;
  }  // if subject already set

  if(location)
  {
    delete [] location;
    location = NULL;
  } // if location already set
  
  if(rhs.subject)
  {
    subject = new char[strlen(rhs.subject) + 1];
    strcpy(subject, rhs.subject);
  }  // if rhs has a subject

  if(rhs.location)
  {
    location = new char[strlen(rhs.location) + 1];
    strcpy(location, rhs.location);
  } // if rhs has a location

  return *this;
} // operator=



