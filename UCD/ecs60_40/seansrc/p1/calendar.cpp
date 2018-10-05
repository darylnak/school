// Author: Sean Davis
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calendar.h"
#include "day.h"

void create(Calendar *calendar)
{
  calendar->count = 0;
  calendar->size = 30;
  calendar->days = (Day*) malloc(30 * sizeof(Day));
} // create()


void dateSearch(Calendar *calendar)
{
  int day = -1, month = -1, year = -1;
  Day dayTemp;
  getDate(&day, &month, &year);
  create(&dayTemp, day, month, year);
  
  for(int i = 0; i < calendar->count; i++)
    if(equal(&calendar->days[i], &dayTemp))
    {
      print(&calendar->days[i]);
      return;
    } // if found matching date
  
  printf("That date was not found.\n");
}  // dateSearch()


void destroy(Calendar *calendar)
{
  for(int i = 0; i < calendar->count; i++)
    destroy(&calendar->days[i]);
   
  free(calendar->days);
}  // destroy()


void getDate(int *day, int *month, int *year)
{
  while(true)
  {
    char line[80], line2[80], *ptr;
    printf("\nPlease enter the month, day, and year (mm/dd/yyyy) >> ");
    
    if (! fgets(line, 80, stdin))
      printf(" is not a valid date.\nPlease try again.\n");
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
      
      printf("%s is not a valid date.\nPlease try again.\n", line2);
    } // else use entered something
  } // while invalid date
}  // getDate()

void readFile(Calendar *calendar)
{
  FILE *fp = fopen("appts.csv", "r");
  char line[80];
  int day, month, year, pos;
  Day dayTemp;
  fgets(line, 80, fp);  // get rid of label line
  
  while(fgets(line, 80, fp))
  {
    month = atoi(strtok(line, "/"));
    day = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, ","));
    create(&dayTemp, day, month, year);
    
    for(pos = 0; 
      pos < calendar->count && !equal(&dayTemp, &calendar->days[pos]); 
      pos++); 
    
    if(pos == calendar->count) // not found
    {
      if(calendar->count == calendar->size)
        resize(calendar);
      
      for(pos = calendar->count - 1; 
        pos >= 0 && lessThan(&dayTemp, &calendar->days[pos]); pos--)
          calendar->days[pos + 1] = calendar->days[pos];
      
      calendar->days[++pos] = dayTemp;  // copy the new day into pos + 1
      calendar->count++;
    } // if not found
    
    read(&calendar->days[pos]);
  } // while more lines in the file
  
  fclose(fp);
}  // readFile()

void resize(Calendar *calendar)
{
  Day *temp = (Day*) malloc(calendar->size * 2 * sizeof(Day));
  
  for(int i = 0; i < calendar->count; i++)
    temp[i] = calendar->days[i];
  
  free(calendar->days);
  calendar->days = temp;
  calendar->size *= 2;
}  // resize()


void subjectSearch(Calendar *calendar)
{
  char subject[80];
  printf("Please enter the subject >> ");
  fgets(subject, 80, stdin);
  
  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'
  
  printf("Date       Start End   Subject      Location\n");
  
  for(int i = 0; i < calendar->count; i++)
    subjectSearch(&calendar->days[i], subject);
  
  printf("\n");
}  // subjectSearch()


