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
  for (int i = 0; i < calendar->count; i++)
  {
    if (equal(&currDay, &(calendar->days[i])))
    {
      print(&(calendar->days[i]));
      fprintf(stdout, "\n");
      return;
    }
  }
  fprintf(stdout, "That date was not found.\n");
}

void destroy(Calendar* calendar)
{
  for (int i = 0; i < calendar->count; i++)
  {
    destroy(&calendar->days[i]);
  }
  free(calendar->days);
}

void getDate(int* const month, int* const day, int* const year)
{
  char* date = NULL;
  char dateCopy[81];
  char *tempMonth, *tempDay, *tempYear;
  char* save = date;

  while(true)
  {
    date = (char*) malloc(sizeof(char) * 81);
    printf("\nPlease enter the month, day, and year (mm/dd/yyyy) >> ");
    fgets(date, 81, stdin);
    date[strlen(date) - 1] = '\0';
    strcpy(dateCopy, date);
    save = date;

    if (strlen(date) > 0)
    {
      tempMonth = strtok_r(save, "/", &save);
      tempDay = strtok_r(save, "/", &save);
      tempYear = strtok_r(save, "/", &save);

      if (tempMonth != NULL && tempDay != NULL && tempYear != NULL)
      {
        if (atoi(tempMonth) > 0 && atoi(tempMonth) < 13 && atoi(tempDay) > 0 &&
            atoi(tempDay) < 32 && atoi(tempYear) > 999 &&
            atoi(tempYear) < 2018)
        {
          *month = atoi(tempMonth);
          *day = atoi(tempDay);
          *year = atoi(tempYear);
          free(date);
          return;
        }
      }
    }
    free(date);
    printf("%s is not a valid date.\nPlease try again.\n", dateCopy);
  }
}

void readFile(Calendar* calendar)
{
  FILE* file = fopen("appts.csv", "r");
  Day dayTemp;
  int day, month, year, i = 0;
  char currLine[100];

  fgets(currLine, 100, file);
  while (fgets(currLine, 100, file) != NULL && file != NULL)
  {
    resize(calendar);
    month = atoi(strtok(currLine, "/,"));
    day = atoi(strtok(NULL, "/,"));
    year = atoi(strtok(NULL, "/,"));
    create(&dayTemp, month, day, year);
    for (i = 0; i < calendar->count; i++)
    {
      if (equal(&dayTemp, &(calendar->days[i])))
        break;
      else if (lessThan(&dayTemp, &calendar->days[i]))
      {
        for (int j = calendar->count; j > i; j--)
          calendar->days[j] = calendar->days[j - 1];
        calendar->days[i] = dayTemp;
        calendar->count += 1;
        break;
      }
    }
    if (i == calendar->count)
    {
      calendar->days[i] = dayTemp;
      calendar->count += 1;
    }
    read(&calendar->days[i]);
  }
  fclose(file);
}

void resize(Calendar* calendar)
{
  if (calendar->count == calendar->size)
  {
    Day* newDays = (Day*) malloc(sizeof(Day) * (2 * calendar->size));

    for (int i = 0; i < calendar->size; i++)
    {
      newDays[i].month = calendar->days[i].month;
      newDays[i].day = calendar->days[i].day;
      newDays[i].year = calendar->days[i].year;
      newDays[i].apptCount = calendar->days[i].apptCount;
      for (int j = 0; j < calendar->days[i].apptCount; j++)
      {
        newDays[i].appts[j] = calendar->days[i].appts[j];
      }
    }
    calendar->size *= 2;
    free(calendar->days);
    calendar->days = newDays;
  }
  return;
}

void subjectSearch(Calendar* calendar)
{
  char subject[81];

  fprintf(stdout, "Please enter the subject >> ");
  fgets(subject, 81, stdin);
  subject[strlen(subject) - 1] = '\0';

  fprintf(stdout, "Date       Start End   Subject      Location\n");
  for (int i = 0; i < calendar->count; i++)
  {
    subjectSearch(&calendar->days[i], subject);
  }
  printf("\n");
  fflush(stdout);
}
