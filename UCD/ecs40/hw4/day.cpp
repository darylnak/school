#include <iostream>
#include <iomanip>

#include "day.h"

using namespace std;

Day::Day() : month(-1), day(-1), year(-1), apptCount(0)
{ } // Day default constructor

Day::Day(int currMonth, int currDay, int currYear) :
  month(currMonth), day(currDay), year(currYear), apptCount(0)
{ } // Day standard constructor

void Day::destroy()
{
  for (int i = 0; i < apptCount; i++)
  {
    appts[i]->destroy();
    delete appts[i];
  } // for every appointment
} // destroy()

bool Day::equal(const Day* day2) const
{
  if (month == day2->month && day == day2->day
      && year == day2->year) // if days equal, return true
    return true;

  return false; // days not equal
} // equal()

bool Day::lessThan(const Day* day2) const
{
  if (year < day2->year)
    return true; // day1 is less than because year

  if (year == day2->year)
  {
    if (month < day2->month)
      return true; // day1 less by month

    if (month == day2->month)
    {
      if (day < day2->day)
        return true; // day1 less by day
    } // else if months are same
  } // else if years are same

  return false; // day1 is not less
} // lessThan()

void Day::print() const
{
  cout << "Start End   Subject      Location" << endl;

  for (int i = 0; i < apptCount; i++) // for each appointment print
    appts[i]->print();
} // print()

void Day::read()
{
  Appointment* appt = new Appointment;
  int i = 0;
  appt->read();

  for (i = 0; i < apptCount; i++)
  {
    if (appt->lessThan(appts[i]))
    {
      for (int j = apptCount; j > i; j--) // for each appointment
        appts[j] = appts[j - 1];

      appts[i] = appt;
      apptCount += 1;
      return;
    } // if appointment less than, insert appropriately
  } // for each appointment

  appts[i] = appt;
  apptCount += 1;
  return;
} // read()

void Day::subjectSearch(const char* subject) const
{
  for (int i = 0; i < apptCount; i++)
  {
    // check subject equality
    if (appts[i]->equal(subject))
    {
      cout << setw(2) << month << "/";
      cout << setw(2) << day << "/";
      cout << setw(2) << year << " ";
      appts[i]->print();
    } // if subject are equal
  } // for each appointment
} // subjectSearch()
