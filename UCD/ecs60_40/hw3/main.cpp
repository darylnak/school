#include <iostream>
#include "calendar.h"

using namespace std;

int getChoice()
{
  int choice;
  char line[80];

  while(true)
  {
    cout << "Calendar Menu\n";
    cout << "0. Done\n";
    cout << "1. Search for date.\n";
    cout << "2. Search for subject.\n";
    cout << "3. Add an appointment.\n";
    cout << "4. Print appointment count.\n";
    cout << "\nYour choice >> ";
    cin >> choice;

    if(choice >= 0 && choice < 5)
      break;

    cout << "Choice must be between 0 and 4.  Please try again.\n\n";
  }  // while invalid choice

  cin.getline(line, 80);
  return choice;
} // getChoice()


int main()
{
  Calendar* calendar = new Calendar;
  calendar->readFile();

  while(1)
  {
    switch (getChoice())
    {
      case 0: delete calendar;
        return 0;
      case 1: calendar->dateSearch();
        break;
      case 2: calendar->subjectSearch();
        break;
      case 3: calendar->addAppointment();
        break;
      case 4: Appointment::getCount();
        break;
    } // execute according to getChoice()
  } // while choice not 0.

  delete calendar;
  return 0;
} // main())
