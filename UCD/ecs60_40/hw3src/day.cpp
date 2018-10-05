// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include "day.h"
#include "appt.h"

using namespace std;

void Day::create(int day1, int month1, int year1)
{
  day = day1;
  month = month1;
  year = year1;
  apptCount = 0;
}  // create()


void Day::destroy()
{
  for(int i = 0; i < apptCount; i++)
  {
    appts[i]->destroy();
    delete appts[i];
  } // for each appointment
}  // destroy()


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
      cout << right << setw(2) << month << "/" << setw(2) << day << "/" 
        << setw(2) << year << ' ';
      appts[i]->print();
    } // if appointment has the subject
      
} // subjectSearch()
