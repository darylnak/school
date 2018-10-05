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


bool Day::equal(const Day *day2) const
{
  return day == day2->day && month == day2->month 
    && year == day2->year;
} // equal()


void Day::insert(Appointment *appointment)
{
  int pos;
  
  for(pos = apptCount - 1; 
    pos >= 0 && appointment->lessThan(appts[pos]); pos--)
      appts[pos + 1] = appts[pos];
  
  appts[pos + 1] = appointment;
  apptCount++;
}  // insert()

bool Day::lessThan(const Day *day2) const
{
  return (year < day2->year)
    || (year == day2->year && month < day2->month)
    || (year == day2->year && month == day2->month 
      && day < day2->day); 
} // lessThan()



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


void Day::print() const
{
  cout << "Start End   Subject      Location\n";
  
  for(int i = 0; i < apptCount; i++)
    appts[i]->print();
  
  cout << "\n";
} // print90

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
    if(appts[i]->equal(subject))
    {
      dayOfWeek.read(month, day, year);
      dayOfWeek.print();
      appts[i]->print();
    } // if appointment has the subject
      
} // subjectSearch()
