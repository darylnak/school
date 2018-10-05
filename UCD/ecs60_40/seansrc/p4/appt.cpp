// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <string.h>
#include "appt.h"
#include "time.h"

using namespace std;

int Appointment::count = 0;

Appointment::Appointment() : subject(NULL), location(NULL)
{
  count++;
} // Appointment()


Appointment::Appointment(const Appointment &appt) : startTime(appt.startTime),
  endTime(appt.endTime), subject(NULL), location(NULL)
{
  if(appt.subject)
  {
    subject = new char[strlen(appt.subject) + 1];
    strcpy(subject, appt.subject);
  }  // if appt.subject not NULL

  if(appt.location)
  {
    location = new char[strlen(appt.location) + 1];
    strcpy(location, appt.location);
  } // if appt.location not NULL
}  // Appointment copy constructor


Appointment::~Appointment()
{
  delete [] subject;
  delete [] location;
}  // ~Appointment()


void Appointment::addAppointment()
{
  char line[1000];
  cout << "Subject >> ";
  cin.getline(line, 1000);
  subject = new char[strlen(line) + 1];
  strcpy(subject, line);
  cout << "Location >> ";
  cin.getline(line, 1000);
  location = new char[strlen(line) + 1];
  strcpy(location, line);
  cout << "Start time (hh:mm) >> ";
  startTime.getTime();
  cout << "End time (hh:mm) >> ";
  endTime.getTime();
}  // addAppointment()


int Appointment::getCount()
{
  return count;
}  // getCount()


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



