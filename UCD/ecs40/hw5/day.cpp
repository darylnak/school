// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include "day.h"
#include "appt.h"
#include "DayOfWeek.h"

using namespace std;

Day::Day() : apptCount(0)
{
}  // Day()


Day::Day(int day1, int month1, int year1) : day(day1), month(month1),
  year(year1), apptCount(0)
{
}  // Day(int, int, int)


Day::~Day()
{
  for(int i = 0; i < apptCount; i++)
    delete appts[i];
}  // destroy()


void Day::addAppointment()
{
  Appointment *appointment = new Appointment();
  appointment->addAppointment();
  insert(appointment);

}  // addAppointment()


bool Day::operator==(const Day &rhs) const
{
  return day == rhs.day && month == rhs.month
    && year == rhs.year;
} // operator==()


void Day::insert(Appointment *appointment)
{
  int pos;

  for(pos = apptCount - 1;
    pos >= 0 && appointment < appts[pos]; pos--)
      appts[pos + 1] = appts[pos];

  appts[pos + 1] = appointment;
  apptCount++;
}  // insert()

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

  for(int i = 0; i < apptCount; i++)
    delete appts[i];

  day = rhs.day;
  month = rhs.month;
  year = rhs.year;

  for(int i = 0; i < rhs.apptCount; i++)
    appts[i] = new Appointment(*rhs.appts[i]);

  apptCount = rhs.apptCount;

  return *this;
}  // operator=


std::ostream& operator<<(std::ostream &os, const Day &rhs)
{
  os << "Start End   Subject      Location\n";

  for(int i = 0; i < rhs.apptCount; i++)
    os << *rhs.appts[i];

  os << "\n";

  return os;
} // operator<<()

void Day::read()
{
  Appointment *appointment = new Appointment;
  appointment->read();
  insert(appointment);
} // read()


void Day::subjectSearch(const char *subject) const
{
  DayOfWeek dayOfWeek;

  for(int i = 0; i < apptCount; i++)
    if(*appts[i] == subject)
    {
      dayOfWeek.read(month, day, year);
      cout << dayOfWeek;
      cout << *appts[i];
    } // if appointment has the subject

} // subjectSearch()
