// Author: Sean Davis
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "calendar.h"
#include "day.h"

using namespace std;

Calendar::Calendar()
{
  count = 0;
  size = 30;
  days = new Day[30];
} // create()


Calendar::~Calendar()
{
  delete [] days;
}  // ~Calendar()


void Calendar::addAppointment()
{
  int pos, day, month, year;
  getDate(&day, &month, &year);
  pos = findDate(day, month, year);
  days[pos].addAppointment();
  
  
}  // addAppointment()


void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  
  for(int i = 0; i < count; i++)
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
     pos < count && ! (dayTemp == days[pos]); pos++); 

  if(pos == count) // not found
  {
    if(count == size)
      resize();

    for(pos = count - 1; 
      pos >= 0 && dayTemp < days[pos]; pos--)
        days[pos + 1] = days[pos];

    days[++pos] = dayTemp;  // copy the new day into pos + 1
    count++;
  } // if not found
  
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
    is >> calendar.days[pos];
  } // while more lines in the file
  
  return is;
}  // operator>> ()

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


