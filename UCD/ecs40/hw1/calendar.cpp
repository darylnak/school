#include "calendar.h"

#include <stdlib.h>

void create(Calendar* calendar) {
  calendar = (Calendar*) malloc(sizeof(Calendar));
  calendar->days = (Day*) malloc(sizeof(Day) * 30);
}
