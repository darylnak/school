#ifndef P6_WEEKLYAPPT_H
#define P6_WEEKLYAPPT_H

#include "appt.h"

class WeeklyAppointment : public Appointment
{
  char series[8];
  int seriesCount;
public:
  WeeklyAppointment(const WeeklyAppointment &wap);
  WeeklyAppointment();
  ~WeeklyAppointment();
  WeeklyAppointment* clone();
  const char* getSeries() const;
  int getSeriesCount() const;
  istream& read(istream &is);
  ostream& write(ostream&) const;
}; // class WeeklyAppointment

#endif //P6_WEEKLYAPPT_H
