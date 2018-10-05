#include "calendar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(Calendar* calendar)
{
  calendar->days = (Day*) malloc(sizeof(Day) * 30);
  calendar->size = 30;
  calendar->count = 0;
} // create()

void dateSearch(Calendar* calendar)
{
  int month, day, year = 0;
  Day currDay;

  getDate(&month, &day, &year);
  create(&currDay, month, day, year);

  for (int i = 0; i < calendar->count; i++)
  {
    // dates are equal
    if (equal(&currDay, &(calendar->days[i])))
    {
      print(&(calendar->days[i]));
      fprintf(stdout, "\n");
      return;
    } // if equal dates
  } // for each day

  fprintf(stdout, "That date was not found.\n");
} // dateSearch()

void destroy(Calendar* calendar)
{
  for (int i = 0; i < calendar->count; i++)
  {
    destroy(&calendar->days[i]);
  } // for each day

  free(calendar->days);
  free(calendar);
} // destroy()

void getDate(int* const month, int* const day, int* const year)
{
  char dateCopy[81];
  char *date, *tempMonth, *tempDay, *tempYear;
  char* save;

  while(true)
  {
    date = (char*) malloc(sizeof(char) * 81);
    printf("\nPlease enter the month, day, and year (mm/dd/yyyy) >> ");
    fgets(date, 81, stdin);
    date[strlen(date) - 1] = '\0';
    strcpy(dateCopy, date);
    save = date;

    if (strlen(date) > 0) // get string length
    {
      tempMonth = strtok_r(save, "/", &save);
      tempDay = strtok_r(save, "/", &save);
      tempYear = strtok_r(save, "/", &save);
      // check date
      if (tempMonth != NULL && tempDay != NULL && tempYear != NULL)
        if (atoi(tempMonth) > 0 && atoi(tempMonth) < 13 && atoi(tempDay) > 0
            && atoi(tempDay) < 32 && atoi(tempYear) > 999
            && atoi(tempYear) < 2018) // valid date
        {
          *month = atoi(tempMonth);
          *day = atoi(tempDay);
          *year = atoi(tempYear);
          free(date);
          return;
        } // if valid date // if each temp variable has a value
    } // if a string was read

    free(date);
    printf("%s is not a valid date.\nPlease try again.\n", dateCopy);
  } // loop until return
} // getDate()

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
    { // days are equal
      if (equal(&dayTemp, &calendar->days[i]))
        break;
      // day1 less than day2
      if (lessThan( &dayTemp, &calendar->days[i]))
      {
        for (int j = calendar->count; j > i; j--) // for each day
          calendar->days[j] = calendar->days[j - 1];

        shift(calendar, &dayTemp, i);
        break;
      } // check if days less than
    } // for each day

    largest(calendar, &dayTemp, i);
    read(&calendar->days[i]);
  } // while there is more to be read & file was opened

  fclose(file);
} // readFile()

void shift(Calendar* calendar, Day* dayTemp, int i)
{
  calendar->days[i] = *dayTemp;
  calendar->count += 1;
} // shift()

void largest(Calendar* calendar, Day* dayTemp, int i)
{
  // largest date in array
  if (i == calendar->count)
  {
    calendar->days[i] = *dayTemp;
    calendar->count += 1;
  } // if largest day
} // largest()

void resize(Calendar* calendar)
{
  if (calendar->count == calendar->size) // calendar is full
  {
    Day* daysNew = (Day*) malloc(sizeof(Day) * (2 * calendar->size));

    for (int i = 0; i < calendar->size; i++)
    {
      daysNew[i].month = calendar->days[i].month;
      daysNew[i].day = calendar->days[i].day;
      daysNew[i].year = calendar->days[i].year;
      daysNew[i].apptCount = calendar->days[i].apptCount;
      // for each appointment, copy
      for (int j = 0; j < calendar->days[i].apptCount; j++)
        daysNew[i].appts[j] = calendar->days[i].appts[j];

    } // for each day

    calendar->size *= 2;
    free(calendar->days);
    calendar->days = daysNew;
  } // if the calendar is full

  return;
} // resize()

void subjectSearch(Calendar* calendar)
{
  char subject[81];

  fprintf(stdout, "Please enter the subject >> ");
  fgets(subject, 81, stdin);
  subject[strlen(subject) - 1] = '\0';
  fprintf(stdout, "Date       Start End   Subject      Location\n");
  // for each day, check for subject in days array
  for (int i = 0; i < calendar->count; i++)
    subjectSearch(&calendar->days[i], subject);

  printf("\n");
  fflush(stdout);
} // subjectSearch()
