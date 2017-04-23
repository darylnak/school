#include <iostream>
#include <string.h>

#include "calendar.h"

using namespace std;

int getChoice();

int main(void)
{
  Calendar* calendar = new Calendar;

  calendar->create();
  calendar->readFile();

  while(true)
  {
    switch (getChoice())
    {
      case 0: calendar->destroy();
        return 0;
      case 1: calendar->dateSearch();
        break;
      case 2: calendar->subjectSearch();
        break;
    } // execute choice
  } // while user has not exited, go
} // main()

int getChoice()
{
  int choice = -1;
  int check = 1;

  while(check)
  {
    cout << "Calendar Menu\n0. Done\n1. Search for date.\n2.";
    cout << " Search for subject.\n\nYour choice >> ";
    // scan choice and check
    cin >> choice;

    if (choice >= 0 && choice <= 2)
    {
      int c;

      while((c = getchar()) != '\n' && c != EOF); // flush stdin

      return choice;
    } // if choice is entered
    else // reprompt user
      cout << "Choice must be between 0 and 2.  Please try again.\n\n";
  } // while user has not entered valid input

  return -1;
} // getChoice()
