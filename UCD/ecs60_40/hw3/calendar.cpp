#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "calendar.h"

using namespace std;

Calendar::Calendar() : days(new Day[30]), size(30), count(0)
{

} // Calendar constructor

void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;

  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);

  for(int i = 0; i < count; i++)
    if(days[i].equal(&dayTemp))
    {
      days[i].print();
      return;
    } // if found matching date

  cout << "That date was not found.\n";
}  // dateSearch

Calendar::~Calendar()
{
    delete [] days;
}  // Calendar destructor

void Calendar::addAppointment()
{
  int day, month, year;
  char subject[80];
  char location[80];
  char startTime[6];
  char endTime[6];
  char line [100] = "dummy,";

  this->getDate(&day, &month, &year);
  cout << "Subject >> ";
  fgets(subject, 80, stdin);
  cout << "Location >> ";
  fgets(location, 80, stdin);
  cout << "Start time (hh:mm) >> ";
  cin >> startTime;
  cout << "End time (hh:mm) >> ";
  cin >> endTime;
  // get rid of new line
  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';
  // get rid of new line
  if(strlen(location) > 0)
    location[strlen(location) - 1] = '\0';

  strcat(line, subject);
  strcat(line, ",");
  strcat(line, startTime);
  strcat(line, ":");
  strcat(line, endTime);
  strcat(line, ":,");
  strcat(line, location);
  strtok(line, ",");

  Day* dayTemp = new Day(day, month, year);
  dayTemp->addRead();
  this->rejectOrInsert(dayTemp);
} // addAppointment()

void Calendar::rejectOrInsert(Day* dayTemp)
{
  int i;

  for (i = 0; i < count; i++)
    if (dayTemp->equal(&days[i]) && dayTemp->isDuplicate(&days[i]))
      return;

  if (count == size)
    resize();

  for (i = 0; i < count; i++)
  { // days are equal
    if (dayTemp->equal(&days[i]))
      break;
    // day1 less than day2
    if (dayTemp->lessThan(&days[i]))
    {
      for (int j = count; j > i; j--) // for each day
        days[j] = days[j - 1];

      days[i] = *dayTemp;
      Appointment::count++;
      count++;
      return;
    } // check if days less than
  } // for each day

  if (i == count)
  {
    days[i] = *dayTemp;
    Appointment::count++;
    count++;
    return;
  } // if largest day

  days[i].insertAppt(dayTemp);
} // findDuplicate()

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

void Calendar::readFile()
{
  ifstream inf("appts.csv");
  char line[80];
  int day, month, year, pos;
  inf.getline(line, 80);  // get rid of label line;

  while(inf.getline(line, 80))
  {
    month = atoi(strtok(line, "/"));
    day = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, ","));
    Day dayTemp(day, month, year);

    for(pos = 0;
      pos < count && !dayTemp.equal(&days[pos]); pos++);

    if(pos == count) // not found
    {
      if(count == size)
        resize();

      for(pos = count - 1;
        pos >= 0 && dayTemp.lessThan(&days[pos]); pos--)
          days[pos + 1] = days[pos];

      days[++pos] = dayTemp;  // copy the new day into pos + 1
      count++;
    } // if not found

    days[pos].read();
  } // while more lines in the file

  inf.close();
}  // readFile()

void Calendar::resize()
{
  Day *temp = new Day[size * 2];

  for(int i = 0; i < count; i++)
    temp[i] = days[i];

  delete [] days;
  days = temp;
  size *= 2;
}  // resize()


void Calendar::subjectSearch() const
{
  char subject[80];
  cout << "Please enter the subject >> ";
  fgets(subject, 80, stdin);

  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'

  cout << "Date                          Start End   Subject      Location\n";

  for(int i = 0; i < count; i++)
    days[i].subjectSearch(subject);

  cout << "\n";
}  // subjectSearch()
