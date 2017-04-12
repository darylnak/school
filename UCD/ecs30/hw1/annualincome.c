#include <stdio.h>

int main() {

   double hourlyWage                   = 0.0;
   double numDollars                   = 0.0;
   double numCents                     = 0.0;
   const int HOURS_PER_WEEK            = 40;
   const int WEEKS_PER_YEAR            = 52;

   printf("What is your hourly wage? ");
   scanf("%lf", &hourlyWage);

   // algorithm for calcutating amount of dollars and cents.
   numDollars = (hourlyWage * HOURS_PER_WEEK * WEEKS_PER_YEAR);
   numCents = (((hourlyWage * HOURS_PER_WEEK * WEEKS_PER_YEAR) - (int)numDollars) * 100.0) + 0.5;

   printf("Your total income over a year is %d dollars and %d cents\n", (int)numDollars, (int)numCents);

   return 0;
}
