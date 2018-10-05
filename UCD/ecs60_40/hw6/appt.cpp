// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <cstring>
#include "appt.h"

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


bool Appointment::operator==(const char *rhs) const
{
  return strstr(subject, rhs) != NULL;
}  // operator==()


bool Appointment::operator<(const Appointment &rhs) const
{
  return startTime < rhs.startTime;
}  // operator<()


ostream& operator<<(ostream& os, const Appointment &appt)
{
  os << appt.startTime << appt.endTime << left
     << setw(13) << appt.subject << appt.location << right << endl;

  return os;
} // operator<<()


std::istream& operator>>(std::istream &inf, Appointment &appt)
{
  char ptr[80];
  inf.seekg(1, ios::cur);
  inf.getline(ptr, 80, ',');
  appt.subject = new char[strlen(ptr) + 1];
  strcpy(appt.subject, ptr);
  inf >> appt.startTime;
  inf >> appt.endTime;
  inf.getline(ptr, 80);
  appt.location = new char[strlen(ptr) + 1];
  strcpy(appt.location, ptr);

  return inf;
} // operator>>()
