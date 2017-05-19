// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include "day.h"
#include "appt.h"
#include "DayOfWeek.h"

using namespace std;

Day::Day() :  day(-1), month(-1), year(-1), apptCount(0)
{ } // Day default constructor

Day::Day(int day1, int month1, int year1) :
day(day1), month(month1), year(year1), apptCount(0)
{ }  // Day standard constructor

Day& Day::operator=(const Day &rhs)
{
  if (this == &rhs)
    return *this;

  for (int i = 0; i < apptCount; i++)
  {
    delete appts[i];
  }

  day = rhs.day;
  month = rhs.month;
  year = rhs.year;
  apptCount = rhs.apptCount;

  for (int i = 0; i < apptCount; i++)
    appts[i] = new Appointment(*rhs.appts[i]);

  return *this;
} // Day operator=

Day::~Day()
{
  // for each appointment
  for(int i = 0; i < apptCount; i++)
    delete appts[i];

}  // Day destructor


bool Day::equal(const Day *day2) const
{
  return day == day2->day && month == day2->month
    && year == day2->year;
} // equal()


bool Day::lessThan(const Day *day2) const
{
  return (year < day2->year)
    || (year == day2->year && month < day2->month)
    || (year == day2->year && month == day2->month
      && day < day2->day);
} // lessThan()


void Day::print() const
{
  cout << "Start End   Subject      Location\n";

  for(int i = 0; i < apptCount; i++)
    appts[i]->print();

  cout << "\n";
} // print90

void Day::read()
{
  int pos;
  Appointment *appointment = new Appointment;
  appointment->read();

  for(pos = apptCount - 1;
    pos >= 0 && appointment->lessThan(appts[pos]); pos--)
      appts[pos + 1] = appts[pos];

  appts[pos + 1] = appointment;
  apptCount++;
} // read()


void Day::subjectSearch(const char *subject) const
{
  for(int i = 0; i < apptCount; i++)
    if(appts[i]->equal(subject))
    {
      DayOfWeek* dow = new DayOfWeek;

      dow->read(month, day, year);
      dow->print();

      appts[i]->print();
    } // if appointment has the subject

} // subjectSearch()
