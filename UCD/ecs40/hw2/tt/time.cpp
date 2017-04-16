// 1
// Author: Sean Davis

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;


void Time::read()
{
  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  char *ptr = strtok(NULL, ",");

  if(strchr(ptr, 'P') && hour != 12)
    hour += 12;
} // read()


void Time::print()const
{
  cout << setw(2) << setfill('0') << right << hour << ":" << setw(2) << minute
    << " " << setfill(' ');
} // print()
