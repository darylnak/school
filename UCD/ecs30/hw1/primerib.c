#include <stdio.h>

int main() {

   double numPounds                = 0.0;
   int numHours                    = 2.0;
   double numMinutes               = 0.0;
   double numSeconds               = 0.0;
   const int CONST_MULT_PER_POUND  = 5;
   const int TIME_CONVERSION_CONST = 60;

   printf("How many pounds is your prime rib? ");
   scanf("%lf", &numPounds);

   // gets number of hours from total minutes.
   numHours += (CONST_MULT_PER_POUND * numPounds) / TIME_CONVERSION_CONST;
   // get total minutes and subtract current amount of hours in minutes.
   // 0.01 in case occurence of 0.999... weird rounding.
   numMinutes = ((CONST_MULT_PER_POUND * numPounds) - (TIME_CONVERSION_CONST * ((float)numHours - 2.0))) + 0.01;

   // since minutes is a float value, subtract integer value to get total seconds.
   // 0.01 in case occurence of 0.999... weird rounding.
   numSeconds = ((numMinutes - (int)numMinutes) * TIME_CONVERSION_CONST) + 0.01;

   printf("Your rib will be in the oven for %d hours, %d minutes, and %d seconds.\n", (int)numHours, (int)numMinutes, (int)numSeconds);

   return 0;
}
