#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "weeklyappt.h"


WeeklyAppointment::WeeklyAppointment() : Appointment(), seriesCount(0)
{
} // WeeklyAppointment()


WeeklyAppointment::WeeklyAppointment(const WeeklyAppointment &wap) :
Appointment(wap)
{
  strcpy(series, wap.series);
  seriesCount = wap.seriesCount;
} // WeeklyAppointment()


WeeklyAppointment::~WeeklyAppointment()
{
} // ~WeeklyAppointment()


WeeklyAppointment* WeeklyAppointment::clone()
{
  WeeklyAppointment *newAppt = new WeeklyAppointment(*this);

  return newAppt;
} // clone()


const char* WeeklyAppointment::getSeries() const
{
  return series;
} // getSeries()


int WeeklyAppointment::getSeriesCount() const
{
  return seriesCount;
} // getSeriesCount()


istream& WeeklyAppointment::read(istream &is)
{
  char count[5];

  Appointment::read(is);
  is.getline(series, 8, ',');
  is.getline(count, 5);

  seriesCount = atoi(count);

  return is;
} // read()


ostream& WeeklyAppointment::write(ostream& os) const
{
  Appointment::write(os) << left << setw(8) << series
                         << '(' << seriesCount << ')' << right;

  return os;
} // write()
