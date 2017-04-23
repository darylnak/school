/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   calendar.h
 * Author: darylnak
 *
 * Created on April 22, 2017, 9:37 AM
 */

#ifndef CALENDAR_H
#define CALENDAR_H

#include <fstream>

#include "day.h"

class Calendar {
public:
  Day* days;
  int size;
  int count;
  
  void shift(Day* dayTemp, int i);
  void largest(const Day* dayTemp, int i);
  void create();
  void readFile();
  void resize();
  void dateSearch() const;
  void getDate(int* month, int* day, int* year) const;
  void subjectSearch() const;
  void destroy();
private:

}; // class Calendar

#endif /* CALENDAR_H */

