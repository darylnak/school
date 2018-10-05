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
  if(subject)
    delete [] subject;
    
  if(location)
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

Appointment* Appointment::clone()
{
  Appointment *newAppt = new Appointment(*this);

  return newAppt;
} // clone()

int Appointment::getCount()
{
  return count;
}  // getCount()


istream& Appointment::read(istream &is)
{
  char line[80];

  is.getline(line, 80, ',');
  subject = new char[strlen(line) + 1];
  strcpy(subject, line);
  is >> startTime;
  is >> endTime;
  is.getline(line, 80, ',');
  location = new char[strlen(line) + 1];
  strcpy(location, line);

  return is;
} // read()

bool Appointment::operator== (const char *subject2)const
{
  return strstr(subject, subject2) != NULL;
}  // operator==()


bool Appointment::operator< (const Appointment &appointment2) const
{
  return startTime < appointment2.startTime; 
}  // operator< ()


ostream& operator<< (ostream &os, const Appointment &appointment)
{
  appointment.write(os);

  return os;
} // operator<< ()


ostream& Appointment::write(ostream& os) const
{
  os << startTime << endTime << left << setw(13)
     << subject << left << setw(26) << location;

  return os;
} // write()