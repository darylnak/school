// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include "appointment.h"
#include "day.h"
#include "dayofweek.h"

using namespace std;

Day::Day() : apptCount(0)
{
} // Day()


Day::~Day()
{
  for(int j = 0; j < apptCount; j++)
    delete  appts[j];
} // ~Day()


int Day::compareDate(short mo, short d) const
{
  if(month == mo)
    return day - d;
  else
    return month - mo;
}


void Day::print() const
{
  DayOfWeek dayOfWeek(month, day);
  dayOfWeek.read();
  dayOfWeek.print();
} // print()


void Day::printAppts() const
{
  for(int j = 0; j < apptCount; j++)
    appts[j]->print();
}  // printAppts()


void Day::printSubject(const char *s, bool &found) const
{
  for(int j = 0; j < apptCount; j++)
    if(appts[j]->compareSubject(s))
    {
      if(!found)
        cout << "Date                           Start End   Subject         "
          << "Location\n";

      print();
      appts[j]->print();
      found = true;
    } // if appts matched subject
} // printSubject()


void Day::read()
{
  appts[apptCount] =  new Appointment;
  appts[apptCount++]->read();
} // read()


void Day::reset(short mo, short d)
{
  month = mo;
  day = d;

  for(int j = 0; j < apptCount; j++)
    delete  appts[j];

  apptCount = 0;
}  // setDate()


Day& Day::operator= (const Day &d)
{
  if(this == &d)
    return *this;

  for(int j = 0; j < apptCount; j++)
    delete  appts[j];

  day = d.day;
  month = d.month;
  apptCount = d.apptCount;

  for(int i = 0; i < apptCount; i++)
  {
    appts[i] = new Appointment();
    *appts[i] = *d.appts[i];
  }

  return *this;
}  // operator=
