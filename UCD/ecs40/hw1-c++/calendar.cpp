/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   calendar.cpp
 * Author: darylnak
 *
 * Created on April 22, 2017, 9:37 AM
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h>

#include "calendar.h"

using namespace std;

void Calendar::create()
{
  days = new Day[30];
  size = 30;
  count = 0;
} // create()

void Calendar::dateSearch() const
{
  int month, day, year = 0;
  Day currDay;

  getDate(&month, &day, &year);
  currDay.create(month, day, year);

  for (int i = 0; i < count; i++)
  {
    // dates are equal
    if (currDay.equal(&days[i]))
    {
      days[i].print();
      cout << endl;
      return;
    } // if equal dates
  } // for each day

  cout << "That date was not found." << endl;
} // dateSearch()

void Calendar::destroy()
{
  for (int i = 0; i < count; i++)
  {
    days[i].destroy();
  } // for each day

  delete days;
  delete this;
} // destroy()

void Calendar::getDate(int*  month, int*  day, int*  year) const
{
  char dateCopy[81];
  char *date, *tempMonth, *tempDay, *tempYear;
  char* save;

  while(true)
  {
    date = new char[81];
    cout << endl << "Please enter the month, day, and year (mm/dd/yyyy) >> ";
    cin.getline(date, 81);
    strcpy(dateCopy, date);
    save = date;

    if (strlen(date) > 0) // get string length
    {
      tempMonth = strtok_r(save, "/", &save);
      tempDay = strtok_r(save, "/", &save);
      tempYear = strtok_r(save, "/", &save);
      // check date
      if (tempMonth != NULL && tempDay != NULL && tempYear != NULL)
        if (atoi(tempMonth) > 0 && atoi(tempMonth) < 13 && atoi(tempDay) > 0
            && atoi(tempDay) < 32 && atoi(tempYear) > 999
            && atoi(tempYear) < 2018) // valid date
        {
          *month = atoi(tempMonth);
          *day = atoi(tempDay);
          *year = atoi(tempYear);
          delete date;
          return;
        } // if valid date // if each temp variable has a value
    } // if a string was read

    delete date;
    cout << dateCopy << "is not a valid date." << endl << "Please try again."
            << endl;
  } // loop until return
} // getDate()

void Calendar::readFile()
{
  ifstream inf("appts.csv");
  Day dayTemp;
  int day, month, year, i = 0;
  char currLine[100];

  inf.getline(currLine, 100);

  while (inf.getline(currLine, 100) && !inf.eof())
  {
    resize();
    month = atoi(strtok(currLine, "/,"));
    day = atoi(strtok(NULL, "/,"));
    year = atoi(strtok(NULL, "/,"));
    dayTemp.create(month, day, year);

    for (i = 0; i < count; i++)
    { // days are equal
      if (dayTemp.equal(&days[i]))
        break;
      // day1 less than day2
      if (dayTemp.lessThan(&days[i]))
      {
        for (int j = count; j > i; j--) // for each day
          days[j] = days[j - 1];

        shift(&dayTemp, i);
        break;
      } // check if days less than
    } // for each day

    largest(&dayTemp, i);
    days[i].read();
  } // while there is more to be read & file was opened

  inf.close();
} // readFile()

void Calendar::shift(Day* dayTemp, int i)
{
  days[i] = *dayTemp;
  count += 1;
} // shift()

void Calendar::largest(const Day* dayTemp, int i)
{
  // largest date in array
  if (i == count)
  {
    days[i] = *dayTemp;
    count += 1;
  } // if largest day
} // largest()

void Calendar::resize()
{
  if (count == size) // calendar is full
  {
    Day* daysNew = new Day[size * 2];

    for (int i = 0; i < size; i++)
    {
      daysNew[i].month = days[i].month;
      daysNew[i].day = days[i].day;
      daysNew[i].year = days[i].year;
      daysNew[i].apptCount = days[i].apptCount;
      // for each appointment, copy
      for (int j = 0; j < days[i].apptCount; j++)
        daysNew[i].appts[j] = days[i].appts[j];

    } // for each day

    size *= 2;
    delete days;
    days = daysNew;
  } // if the calendar is full

  return;
} // resize()

void Calendar::subjectSearch() const
{
  char subject[81];

  cout << "Please enter the subject >> ";
  cin.getline(subject, 81);
  subject[strlen(subject) - 1] = '\0';
  cout << "Date       Start End   Subject      Location" << endl;
  // for each day, check for subject in days array
  for (int i = 0; i < count; i++)
    days[i].subjectSearch(subject);

  cout << endl;
  fflush(stdout);
} // subjectSearch()
