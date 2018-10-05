#include <iostream>
#include <iomanip>
#include <fstream>
#include "day.h"
#include "DayOfWeek.h"

using namespace std;

Day::Day() : apptCount(0)
{
}  // Day()


Day::Day(int day1, int month1, int year1) : day(day1), month(month1),
  year(year1), apptCount(0)
{
}  // Day(int, int, int)

void Day::addAppointment()
{
  Appointment *appointment = new Appointment();
  appointment->addAppointment();
  appts += appointment;

  apptCount++;
}  // addAppointment()


bool Day::operator==(const Day &rhs) const
{
  return day == rhs.day && month == rhs.month
    && year == rhs.year;
} // operator==()


bool Day::operator<(const Day &rhs) const
{
  return (year < rhs.year)
    || (year == rhs.year && month < rhs.month)
    || (year == rhs.year && month == rhs.month
      && day < rhs.day);
} // operator<()


Day& Day::operator= (const Day &rhs)
{
  if(this == &rhs)
    return *this;

  day = rhs.day;
  month = rhs.month;
  year = rhs.year;
  appts = rhs.appts;
  apptCount = rhs.apptCount;

  return *this;
}  // operator=()


std::ostream& operator<<(std::ostream &os, const Day &rhs)
{
  os << "Start End   Subject      Location\n";
  os << rhs.appts << endl;

  return os;
} // operator<<()


std::istream& operator>>(std::istream &inf, Day &day)
{
  Appointment *appointment = new Appointment;
  inf >> *appointment;
  day.appts += appointment;
  day.apptCount++;

  return inf;
} // operator>>()


void Day::subjectSearch(const char *subject) const
{
  DayOfWeek dayOfWeek(month, day, year);
  ifstream inf("DOW.dat", ios::binary);
  Appointment *findSubject = appts.find(subject);

  while(findSubject)
  {
    inf >> dayOfWeek;
    cout << dayOfWeek;
    cout << *findSubject;
    findSubject = appts.find(subject);
  } // find subject
//  for(int i = 0; i < apptCount; i++)
//    if(*appts[i] == subject)
//    {
//      inf >> dayOfWeek;
//      cout << dayOfWeek;
//      cout << *appts[i];
//    } // if appointment has the subject

} // subjectSearch()