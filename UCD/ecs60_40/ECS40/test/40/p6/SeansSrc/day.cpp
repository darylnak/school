// Author: Sean Davis

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "day.h"
#include "appt.h"
#include "DayOfWeek.h"
#include "weeklyappt.h"

using namespace std;

Day::Day()
{
}  // Day()


Day::Day(int day1, int month1, int year1) : day(day1), month(month1), 
  year(year1)
{
}  // Day(int, int, int)


void Day::addAppointment()
{
  Appointment *appointment = new Appointment();
  appointment->addAppointment();
  appts += appointment;
}  // addAppointment()


bool Day::operator== (const Day &day2) const
{
  return day == day2.day && month == day2.month 
    && year == day2.year;
} // operator== ()


bool Day::operator< (const Day &day2) const
{
  return (year < day2.year)
    || (year == day2.year && month < day2.month)
    || (year == day2.year && month == day2.month 
      && day < day2.day); 
} // operator< ()



Day& Day::operator= (const Day &rhs) 
{
  if(this == &rhs)
    return *this;
  
  day = rhs.day;
  month = rhs.month;
  year = rhs.year;
  appts = rhs.appts;
  return *this;
}  // operator= ()


Day& Day::operator+= (const WeeklyAppointment &weeklyAppointment)
{
  appts += new WeeklyAppointment(weeklyAppointment);
  return *this;
} // operator+=


ostream& operator<< (ostream &os, const Day &day)
{
  os << "Start End   Subject      Location\n";
  os << day.appts;
  os << "\n";
  return os;
} // operator<< ()


const Appointment* operator>> (istream &is, Day &day)
{
  char line[80];
  is.getline(line, 80, ',');
  int type = atoi(line);
  Appointment *appointment;
  
  if(type == 0)
  {
    appointment = new Appointment;
    is >> *appointment;
    is.getline(line, 80); // eat up the rest of the line.
  }  // if regular appointment
  else // else is a 1
  {
    appointment = new WeeklyAppointment;
    is >> *appointment;
  }  // else a WeeklyAppointment
  
  day.appts += appointment;
  return appointment;
} // operator>> ()


void Day::subjectSearch(const char *subject) const
{

  const Appointment *appointmentPtr;
  
  while((appointmentPtr = appts.find(subject)))
  {
    ifstream inf("DOW.dat", ios::binary);
    DayOfWeek dayOfWeek(month, day, year);
    inf >> dayOfWeek;
    cout << dayOfWeek;
    cout << *appointmentPtr << endl;
    inf.close();
  } // if appointment has the subject
} // subjectSearch()
