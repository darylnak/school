/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   appt.h
 * Author: darylnak
 *
 * Created on April 22, 2017, 9:35 AM
 */

#ifndef APPT_H
#define APPT_H

#include <stdbool.h>
#include <string.h>

#include "time.h"

class Appointment {
public:
  Time startTime;
  Time endTime;
  char* subject;
  char* location;
  
  void destroy();
  bool equal(const char* currSubject) const;
  bool lessThan(const Appointment* arrAppt) const;
  void print() const;
  void read();
private:

}; // class Appointment

#endif /* APPT_H */

