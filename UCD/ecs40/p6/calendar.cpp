// Author: Sean Davis
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "calendar.h"
#include "day.h"
#include "weeklyappt.h"
#include "DayOfWeek.h"

using namespace std;

Calendar::Calendar() : days(30)
{
} // create()


Calendar::~Calendar()
{
}  // ~Calendar()


void Calendar::addAppointment()
{
  int pos, day, month, year;
  getDate(&day, &month, &year);

  Day object(day, month, year);

  pos = days += object;
  days[pos].addAppointment();
}  // addAppointment()

void Calendar::createSeries(const WeeklyAppointment wap,
                            int day, int month, int year)
{
  ifstream inf("DOW.dat", ios::binary);
  const char *series = wap.getSeries();
  int count = wap.getSeriesCount() - 1, pos;
  int currDay = day, currMonth = month, currYear = year;

  while (count)
  {
    if (currDay + 1 > 31)
    {
      currDay = (currDay + 1) - 31;
      ++currMonth;
    } // check if month needs to be incremented
    else // // day is < 31. Do not increment month
    {
      ++currDay;
    } // day is < 31. Do not increment month

    if (currMonth > 12)
    {
      currMonth = currMonth - 12;
      ++currYear;
    } // check if year needs to be incremented

    DayOfWeek dow(currMonth, currDay, currYear);
    inf >> dow;

    for (size_t j = 0; j < strlen(series); j++)
      if (dow == series[j])
      {
        Day object(currDay, currMonth, currYear);
        pos = days += object;
        days[pos] += wap;
        --count;
      } // check if date is in the series. Add day and appt if so.
  } // loop until seriesCount amount of appointments added
} // createSeries()

void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day object(day, month, year);

  for(int i = 0; i < days.getCount(); i++)
    if(days[i] ==  object)
    {
      cout << days[i];
      return;
    } // if found matching date

  cout << "That date was not found.\n";
}  // dateSearch()


void Calendar::getDate(int *day, int *month, int *year) const
{
  while(true)
  {
    char line[80], line2[80], *ptr;
    cout << "\nPlease enter the month, day, and year (mm/dd/yyyy) >> ";

    if (! fgets(line, 80, stdin))
      cout << " is not a valid date.\nPlease try again.\n";
    else // User entered something
    {
      strtok(line, "\n");
      strcpy(line2, line);
      ptr = strtok(line, "/");

      if(ptr)
      {
        *month = atoi(ptr);
        ptr = strtok(NULL, "/");

        if(ptr)
        {
          *day = atoi(ptr);
          ptr = strtok(NULL, "\n");

          if(ptr)
            *year = atoi(ptr);
        } // if something before a second /
      } // if something before the first /

      if(*day >= 1 && *day <= 31 && *month >= 1 && *month <= 12
         && *year >= 1000 && *year <= 2017)
         break;

      cout << line2 << " is not a valid date.\nPlease try again.\n";
    } // else use entered something
  } // while invalid date
}  // getDate()

istream& operator>> (istream &is, Calendar &calendar)
{
  char line[80];
  const Appointment *check;
  int day, month, year, pos;
  is.getline(line, 80);  // get rid of label line;

  while(is.getline(line, 80, '/'))
  {
    month = atoi(line);
    is.getline(line, 80, '/');
    day = atoi(line);
    is.getline(line, 80, ',');
    year = atoi(line);
    Day object(day, month, year);

    pos = calendar.days += object;
    check = is >> calendar.days[pos];

    if(dynamic_cast<const WeeklyAppointment*>(check))
      calendar.createSeries(*dynamic_cast<const WeeklyAppointment*>(check),
                            day, month, year); // Correct? Why const?
    // why call copy constructor? Why does base accept derivative.
    // how is is the upcast ambiguous?

  } // while more lines in the file

  return is;
}  // operator>> ()


void Calendar::subjectSearch() const
{
  char subject[80];
  cout << "Please enter the subject >> ";
  fgets(subject, 80, stdin);

  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'

  cout << "Date                          Start End   Subject      Location\n";

  for(int i = 0; i < days.getCount(); i++)
    days[i].subjectSearch(subject);

  cout << "\n";
}  // subjectSearch()
