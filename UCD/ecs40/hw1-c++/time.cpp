/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time.cpp
 * Author: darylnak
 * 
 * Created on April 22, 2017, 9:29 AM
 */

#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "appt.h"

using namespace std;

bool Time::lessThan(const Time* time2) const
{
  if (time2->hour == 24 && hour < 24) // if hour is less
    return true;

  if (hour < time2->hour) // else if hour is less
    return true;

  if (hour == time2->hour) // same hours
  {
    if (minute < time2->minute) // time1 minutes < time2 minutes
      return true;
    else // time1 minutes not < time2 minutes
      return false;
  } // if hours are the same

  return false;
} // lessThan()

void Time::print()  const
{
  cout << setw(2) << setfill('0') << hour;
  fflush(stdout);
  cout << ":";
  fflush(stdout);
  cout << minute;
  fflush(stdout);
} // print()

void Time::read()
{
  int hour = atoi(strtok(NULL, "/,:"));
  int minute = atoi(strtok(NULL, "/,:"));
  char* ampm = strchr(strtok(NULL, "/,:"), ' ');

  if (strcmp(ampm, " AM") == 0) // check for AM time
  {
    if (hour == 12) // midnight
    {
      if (minute == 0) // minute(s) are 0
      {
        hour = 24;
        minute = 0;
        return;
      } // if minute(s) are zero
      else // minute(0) are not 0
      {
        hour = 0;
        minute = minute;
        return;
      } // else minute(s) are not zero
    } // if midnight
    else // not midnight
    {
      hour = hour;
      minute = minute;
      return;
    } //  else just return hours and minute(s)
  } // if morning
  else // In PM
  {
    hour = hour + 12;
    minute = minute;
    return;
  } // else time in PM
} // read()
