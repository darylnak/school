#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "calendar.h"

int getChoice();

int main(void)
{
  Calendar* calendar = (Calendar*) malloc(sizeof(Calendar));
  create(calendar);
  readFile(calendar);
  while(true)
  {
    switch (getChoice())
    {
      case 0:
        destroy(calendar);
        return 0;

      case 1:
        dateSearch(calendar);
        break;

      case 2:
        subjectSearch(calendar);
        break;
    }
  }
}

int getChoice()
{
  int choice = -1;
  int check = 1;

  while(check)
  {
    fprintf(stdout, "Calendar Menu\n0. Done\n1. Search for date.\n2.");
    fprintf(stdout, " Search for subject.\n\nYour choice >> ");
    if (fscanf(stdin, "%d", &choice) == 1 && choice >= 0 && choice <= 2)
    {
      int c;
      while((c = getchar()) != '\n' && c != EOF);
      return choice;
    }
    else
      fprintf(stdout, "Choice must be between 0 and 2.  Please try again.\n\n");
  }
  return -1;
}
