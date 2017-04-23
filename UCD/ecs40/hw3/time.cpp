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
  cout << setw(2) << setfill('0') << hour << flush;
  cout << ":" << flush;
  cout << setw(2) << setfill('0') << minute << " " << flush;
} // print()

void Time::read()
{
  hour = atoi(strtok(NULL, "/,:"));
  minute = atoi(strtok(NULL, "/,:"));
  char* ampm = strchr(strtok(NULL, "/,:"), ' ');

  if (strcmp(ampm, " AM") == 0) // check for AM time
  {
    if (hour == 12) // midnight
    {
      if (minute == 0) // minute(s) are 0
      {
        hour = 24;
        return;
      } // if minute(s) are zero

      hour = 0;
      return;
    } // if midnight
  } // if morning
  else // In PM
  {
    if (hour != 12)
    {
      hour += 12;
      return;
    } // if not afternoon
  } // else time in PM
} // read()
