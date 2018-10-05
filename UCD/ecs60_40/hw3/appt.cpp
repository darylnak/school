#include <iostream>
#include <iomanip>
#include <cstring>
#include "appt.h"
#include "time.h"

using namespace std;

int Appointment::count = 0;

Appointment::Appointment() : subject(NULL), location(NULL)
{

} // Appointment default contructor

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


bool Appointment::equal(const char *subject2) const
{
  return strstr(subject, subject2) != NULL;
}  // equal()

bool Appointment::isDuplicate(const Appointment* appt) const
{
  // check if appointment is a duplicate
  if (strcmp(this->subject, appt->subject) == 0 &&
      strcmp(this->location, appt->location) == 0 &&
      this->startTime.equal(&appt->startTime) &&
      this->endTime.equal(&appt->endTime))
    return true;

  return false;
} // isDuplicate()

void Appointment::getCount()
{
  cout << "Appointment count: " << count << "\n\n";
} // getCount()

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

void Appointment::addRead()
{
  char *ptr;
  ptr = strtok(NULL, ",");
  subject = new char[strlen(ptr) + 1];
  strcpy(subject, ptr);
  startTime.addRead();
  endTime.addRead();
  ptr = strtok(NULL, ",");
  location = new char[strlen(ptr) + 1];
  strcpy(location, ptr);
} // add read()

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
