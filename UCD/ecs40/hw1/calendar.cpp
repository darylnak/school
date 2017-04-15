#include "calendar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(Calendar* calendar)
{
  calendar->days = (Day*) malloc(sizeof(Day) * 30);
  calendar->size = 30;
  calendar->count = 0;
}

void dateSearch(Calendar* calendar)
{
  int month, day, year = 0;
  Day currDay;

  getDate(&month, &day, &year);
  create(&currDay, month, day, year);
  for (int i = 0; i < 1; i++)
  {
    printf("curr: %d/%d/%d\n", month, day, year);
    printf("days: %d/%d/%d\n", calendar->days[i].month, calendar->days[i].day, calendar->days[i].year);
    if (equal(&currDay, &(calendar->days[i])))
    {
      print(&(calendar->days[i]));
    }
  }
}

void destroy(Calendar* calendar)
{

}

void getDate(int* const month, int* const day, int* const year)
{
  char date[800];
  char dateCopy[800];
  char *tempMonth, *tempDay, *tempYear;

  while(true)
  {
    printf("Please enter the month, day, and year (mm/dd/yyyy) >> ");
    fgets(date, 800, stdin);
    date[strlen(date) - 1] = '\0';
    strcpy(dateCopy, date);

    if (strlen(date) > 0)
    {
      tempMonth = strtok(date, "/");
      tempDay = strtok(NULL, "/");
      tempYear = strtok(NULL, "/");

      if (tempDay != NULL && tempYear != NULL)
      {
        if (atoi(tempMonth) > 0 && atoi(tempMonth) < 13 && atoi(tempDay) > 0 &&
            atoi(tempDay) < 32 && atoi(tempYear) > 1999 &&
            atoi(tempYear) < 2018)
        {
          *month = atoi(tempMonth);
          *day = atoi(tempDay);
          *year = atoi(tempYear);
          return;
        }
      }
    }
    printf("%s is not a valid date.\nPlease try again.\n\n", dateCopy);
  }
}

void readFile(Calendar* calendar)
{
  FILE* file = fopen("appts2.csv", "r");
  Day dayTemp;
  int day, month, year = 0;
  char currLine[200];
  char* next = fgets(currLine, 200, file);

  if (file != NULL)
  {
    next = fgets(currLine, 200, file);

    for (int i = 0; next != NULL; i++)
    {
      if (calendar->count == calendar->size)
      {
        resize(calendar);
      }
      month = atoi(strtok(currLine, "/"));
      day = atoi(strtok(NULL, "/"));
      year = atoi(strtok(NULL, "/"));
      create(&dayTemp, month, day, year);

      for (int i = calendar->count; i > 0; i--)
      {
        if (equal(&dayTemp, &(calendar->days[i - 1])))
        {
          read(&calendar->days[i - 1]);
        }
        else if (lessThan(&dayTemp, &(calendar->days[i - 1])))
        {
          for (int j = calendar->count; j > i; j--)
          {
            calendar->days[j] = calendar->days[j - 1];
          }
          calendar->days[i - 1] = dayTemp;
          calendar->count += 1;
          break;
        }
        else
        {
          calendar->days[i + 1] = dayTemp;
          calendar->count += 1;
          break;
        }
      }
      next = fgets(currLine, 200, file);
    }
  }
  printf("Count %d\n", calendar->count);
  for (int i = 0; i < calendar->count; i++) {
    printf("Date: %d/%d/%d\n", calendar->days[i].month, calendar->days[i].day, calendar->days[i].year);
  }
  fclose(file);
}

void resize(Calendar* calendar)
{
  Day* newDays = (Day*) malloc(sizeof(Day) * (2 * calendar->size));

  for (int i = 0; i < calendar->size; i++)
  {
    newDays[i].month = calendar->days[i].month;
    newDays[i].day = calendar->days[i].day;
    newDays[i].year = calendar->days[i].year;
  }
  calendar->size *= 2;
  free(calendar->days);
  calendar->days = newDays;
}

void subjectSearch(Calendar* calendar)
{

}
