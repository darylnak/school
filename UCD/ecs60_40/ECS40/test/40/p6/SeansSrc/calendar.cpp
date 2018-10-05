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
} // Calendar()


Calendar::~Calendar()
{
}  // ~Calendar()


void Calendar::addAppointment()
{
  int pos, day, month, year;
  getDate(&day, &month, &year);
  pos = findDate(day, month, year);
  days[pos].addAppointment();
}  // addAppointment()


void Calendar::createSeries(WeeklyAppointment weeklyAppointment, int day, 
                            int month, int year)
{
  int count = 1;
  ifstream inf("DOW.dat", ios::binary);

  while(count < weeklyAppointment.getSeriesCount())
  {
    if(++day > 31)
    {
      day = 1;
      
      if(++month > 12)
      {
        month = 1;
        year++;
      } // if month > 11
    }  // if day exceeds 31
    
    DayOfWeek dayOfWeek(month, day, year);
    inf >> dayOfWeek;
    
    for(const char *ptr = weeklyAppointment.getSeries(); *ptr; ptr++)
      if(dayOfWeek == *ptr)
      {
        int pos = findDate(day, month, year);
        days[pos] += weeklyAppointment;
        count++;
        break;
      }  // if found day match with Weekly
  } // while count less than series.
  
}  // createSeries()


void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  
  for(int i = 0; i < days.getCount(); i++)
    if(days[i] ==  dayTemp)
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


int Calendar::findDate(int day, int month, int year)
{
  int pos; 
  Day dayTemp(day, month, year);
    
  for(pos = 0; 
     pos < days.getCount() && ! (dayTemp == days[pos]); pos++); 

  if(pos == days.getCount()) // not found
    pos = days += dayTemp;
  
  return pos;
}  // findDate()


istream& operator>> (istream &is, Calendar &calendar)
{
  char line[80];
  int day, month, year, pos;
  is.getline(line, 80);  // get rid of label line;
  
  while(is.getline(line, 80, '/'))
  {
    month = atoi(line);
    is.getline(line, 80, '/');
    day = atoi(line);
    is.getline(line, 80, ',');
    year = atoi(line);
    pos = calendar.findDate(day, month, year);
    const Appointment *appointment = is >> calendar.days[pos];
    
    const WeeklyAppointment *weeklyAppointment 
      = dynamic_cast<const WeeklyAppointment*> (appointment);
    
    if(weeklyAppointment != NULL)
      calendar.createSeries(*weeklyAppointment, day, month, year);
    
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


