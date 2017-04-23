/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time.h
 * Author: darylnak
 *
 * Created on April 22, 2017, 9:29 AM
 */

#ifndef TIME_H
#define TIME_H

#include <stdbool.h>

class Time {
public:
  short hour;
  short minute;
  
  void read();
  void print() const;
  bool lessThan(const Time* time2) const;
private:

}; // class Time

#endif /* TIME_H */

