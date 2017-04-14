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
  char date[10];
  int day, month, year = 0;

  fprintf(stdout, "Please enter the month, day, and year (mm/dd/yyyy) >> ");
  fscanf(stdin, "%s", date);
  printf("%d",atoi(strtok()));
  //getDate(&month, &day, &year);
}

void destroy(Calendar* calendar)
{

}

void getDate(char* date) {

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
        resize(calendar);
      month = atoi(strtok(currLine, "/"));
      day = atoi(strtok(NULL, "/"));
      year = atoi(strtok(NULL, "/"));
      create(&dayTemp, month, day, year);

      for (int i = 0; i < calendar->size; i++)
      {
        if (equal(&dayTemp, &(calendar->days[i])))
          read(&dayTemp);
        else if (lessThan(&dayTemp, &(calendar->days[i])))
        {
          for (int j = calendar->size; j > i; j++)
            calendar->days[j] = calendar->days[j - 1];
          calendar->days[i] = dayTemp;
          calendar->count += 1;
        }
      }
      next = fgets(currLine, 200, file);
    }
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
