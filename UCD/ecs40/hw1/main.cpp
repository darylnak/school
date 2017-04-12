#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "calendar.h"

int getChoice();

int main(void) {
  Calendar* calendar;
  create(calendar);
  getChoice();
  return 0;
}

int getChoice() {
  int choice = -1;
  int check = 1;

  while(check) {
    fprintf(stdout, "Calendar Menu\n0. Done\n1. Search for date\n2. Search for subject.\n\nYour choice >> ");
    if (fscanf(stdin, "%d", &choice) == 1 && choice >= 0 && choice <= 2) {
      return choice;
    }
    else {
      fprintf(stdout, "Choice must be between 0 and 2.  Please try again.\n\n");
    }
  }
  return -1;
}
