#include <stdio.h>
#include <math.h>

int main() {

   double currGrade =  0;
   int finalWeight  =  0;
   int finalGrade   =  0;

   printf("What is your current grade? ");
   scanf("%lf", &currGrade);

   printf("How much is the final worth? ");
   scanf("%d", &finalWeight);

   printf("What is your final exam score? ");
   scanf("%d", &finalGrade);

   // algorithm for calculating weighted grade.
   currGrade = (((finalWeight * finalGrade) + ((100 - finalWeight) * currGrade)) / 100);

   printf("Your final grade is %d%%\n", (int)(ceil(currGrade)));

   return 0;
}
