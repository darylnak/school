#include "calendar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(Calendar* calendar) {
  calendar->days = (Day*) malloc(sizeof(Day) * 30);
  calendar->size = 30;
  calendar->count = 0;
}

void readFile(Calendar* calendar) {
  FILE* file = fopen("appts.csv", "r");
  int day, month, year = 0;
  char currLine[200];
  char* next = fgets(currLine, 200, file);

  if (file != NULL) {
    next = fgets(currLine, 200, file);
    for (int i = 0; next != NULL; i++) {
      if (calendar->count == calendar->size) {
        resize(calendar);
      }
      month = atoi(strtok(currLine, "/"));
      day = atoi(strtok(NULL, "/"));
      year = atoi(strtok(NULL, "/"));
      create(&(calendar->days[i]), day, month, year);
      next = fgets(currLine, 200, file);
      calendar->count += 1;
    }
  }
  fclose(file);
}

void resize(Calendar* calendar) {
  Day* newDays = (Day*) malloc(sizeof(Day) * (2 * calendar->size));

  for (int i = 0; i < calendar->size; i++) {
    newDays[i].month = calendar->days[i].month;
    newDays[i].day = calendar->days[i].day;
    newDays[i].year = calendar->days[i].year;
  }
  calendar->size *= 2;
  free(calendar->days);
  calendar->days = newDays;
}
