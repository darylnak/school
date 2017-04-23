/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   day.h
 * Author: darylnak
 *
 * Created on April 22, 2017, 9:33 AM
 */

#ifndef DAY_H
#define DAY_H

#include <stdbool.h>

#include "appt.h"

class Day {
public:
  short month;
  short day;
  short year;
  short apptCount;
  Appointment* appts[8];

  void create(int currMonth, int currDay, int currYear);
  bool equal(const Day* day2) const;
  bool lessThan(const Day* day2) const;
  void read();
  void print() const;
  void subjectSearch(const char* subject) const;
  void destroy();
private:

}; // class Day

#endif /* DAY_H */
