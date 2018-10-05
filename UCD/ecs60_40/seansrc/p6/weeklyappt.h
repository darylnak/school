#ifndef WEEKLYAPPT_H
#define	WEEKLYAPPT_H

#include "appt.h"

class WeeklyAppointment : public Appointment
{
  char series[8];
  int seriesCount;
public:
  WeeklyAppointment();
  WeeklyAppointment(const WeeklyAppointment &weeklyAppointment);
  Appointment* clone() const;
  istream& read (istream &is);
  ostream& write (ostream &os) const;
  int getSeriesCount() const;
  const char* getSeries() const;
}; // class weeklyappt 

#endif	// WEEKLYAPPT_H

