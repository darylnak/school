// Author: Sean Davis

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "appt.h"
#include "weeklyappt.h"
using namespace std;


WeeklyAppointment::WeeklyAppointment()
{
}  //   WeeklyAppointment()


WeeklyAppointment:: WeeklyAppointment(
  const WeeklyAppointment &weeklyAppointment) : Appointment(weeklyAppointment),
    seriesCount(weeklyAppointment.seriesCount)
{
  strcpy(series, weeklyAppointment.series);
} // WeeklyAppointment() copy constructor


Appointment* WeeklyAppointment::clone() const
{
  WeeklyAppointment *ptr = new WeeklyAppointment(*this);
  return ptr;
}  // clone()


int WeeklyAppointment::getSeriesCount() const
{
  return seriesCount;
}  // getCount()


const char* WeeklyAppointment::getSeries() const
{
  return series;
} // getSeries


istream& WeeklyAppointment::read (istream &is)
{
  char line[80];
  Appointment::read(is);
  is.getline(series, 8, ',');
  is.getline(line, 80);
  seriesCount = atoi(line);
  return is;
} // read()



ostream& WeeklyAppointment::write (ostream &os) const
{
  Appointment::write(os);
  os << left << setw(8) << series << '(' << seriesCount << ')';
  return os;
}  // write()


