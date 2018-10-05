// Author: Sean Davis 
// Created on April 2, 2017, 3:51 PM

#include <iostream>
#include "calendar.h"
#include "appt.h"

using namespace std;

int getChoice()
{
  int choice = 0;
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
  Calendar calendar;
  int choice;
  calendar.readFile();
  choice = getChoice();
  
  while(choice)
  {
    switch(choice)
    {
      case 1: calendar.dateSearch(); break;
      case 2: calendar.subjectSearch(); break;
      case 3: calendar.addAppointment(); break;
      case 4: 
        cout << "Appointment count: " << Appointment::getCount()  << "\n\n";
        break;
    }  // switch
    
    choice = getChoice();
  } // while choice not 0.

  return 0;
} // main())

