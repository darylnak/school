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
  char currLine[200];

  if (file != NULL) {
    fgets(currLine, 200, file);
    for (int i = 0; fgets(currLine, 200, file) != NULL; i++) {
      if (calendar->count == calendar->size) {
        resize(calendar);
        printf("Size %d | Count %d\n", calendar->size, calendar->count);
      }
      printf("Current %d\n", calendar->count);
      calendar->days[i].month = atoi(strtok(currLine, "/"));
      calendar->days[i].day = atoi(strtok(NULL, "/"));
      calendar->days[i].year = atoi(strtok(NULL, "/"));
      calendar->count += 1;
    }
  }
}

void resize(Calendar* calendar) {
  calendar = (Calendar*) realloc(calendar, 2 * calendar->size);
  calendar->size *= 2;
}
