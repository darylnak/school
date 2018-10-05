// Author: Sean Davis 
// Created on April 2, 2017, 3:51 PM

#include <stdio.h>
#include "calendar.h"

using namespace std;

int getChoice()
{
  int choice;
  char line[80];
  
  while(true)
  {
    printf("Calendar Menu\n");
    printf("0. Done\n");
    printf("1. Search for date.\n");
    printf("2. Search for subject.\n");
    printf("\nYour choice >> ");
    scanf("%d", &choice);
    
    if(choice >= 0 && choice < 3)
      break;
    
    printf("Choice must be between 0 and 2.  Please try again.\n\n");
  }  // while invalid choice
  
  fgets(line, 80, stdin);
  return choice;
} // getChoice()


int main() 
{
  Calendar calendar;
  int choice;
  create(&calendar);
  readFile(&calendar);
  choice = getChoice();
  
  while(choice)
  {
    if(choice == 1)
      dateSearch(&calendar);
    else // choice not 1
      subjectSearch(&calendar);
  
    choice = getChoice();
  } // while choice not 0.

  destroy(&calendar);
  return 0;
} // main())

