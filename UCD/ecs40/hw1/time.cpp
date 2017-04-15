#include "appt.h"

#include <stdio.h>

void print(Time* appt)
{

}

void read(Time* appt)
{
  char* tempTime = strtok(NULL, "/,");
  printf("%s\n", tempTime);
}
