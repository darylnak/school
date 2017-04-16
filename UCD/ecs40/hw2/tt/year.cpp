// 1
// Author: Sean Davis

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "year.h"
#include "day.h"

using namespace std;


Year::Year():count(0), size(30)
{
  days = new Day[size];
}  // Year()


Year::~Year()
{
  delete [] days;
}  // ~Year()


void Year::addDate(int month, int day)
{
  int i;

  if(count  == size)
  {
    Day *temp =  new Day[size * 2];

    for(int i = 0; i < size; i++)
      temp[i] = days[i];

    delete [] days;
    days = temp;
    size *= 2;
  } // if need to resize

  for(i = 0; i < count; i++)
    if(days[i].compareDate(month, day) > 0)
      break;

  for(int j = count - 1; j >= i; --j)
    days[j + 1] = days[j];  // roll entries toward end

  days[i].reset(month, day);
  count++;
} // addDate()


int Year::findDate(int month, int day) const
{
  for(int i = 0; i < count; i++)
    if(days[i].compareDate(month, day) == 0)
      return i;

  return count; // not found
} // findDate()


void Year::read()
{
  char s[256];
  int month, day;

  ifstream inf("appts.csv");
  inf.getline(s, 256); // eat titles.
  while(inf.getline(s, 256))
  {
    month = atoi(strtok(s,"/"));
    day = atoi(strtok(NULL,"/"));
    strtok(NULL, ","); // read through 2003

    int pos = findDate(month, day);

    if(pos == count)
    {
      addDate(month, day);
      pos = findDate(month, day);
    } // if date not found

    days[pos].read();

  } // while more to read

  inf.close();
} // read()


void Year::searchDate(int month, int day) const
{
  bool found = false;

  for(int i = 0; i < count; i++)
    if(days[i].compareDate(month, day) == 0)
    {
      cout << "Start End   Subject         Location\n";
      days[i].printAppts();
      found = true;
      break;
    } // if day found

  if(!found)
    cout << "There are no appointments for that date.\n";

  cout << endl;
} // searchDate()


void Year::searchSubject(const char *s) const
{
  bool found = false;

  for(int i = 0; i < count; i++)
    days[i].printSubject(s, found);

  if(!found)
    cout << s << " was not found as a subject in the calendar.\n";

  cout << endl;
} // searchSubject()

