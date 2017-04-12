#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

   char userInput;
   char computerOut;
   char computerOutString[10] = "";

   srand((int) time(0));

   printf("Rock, paper, or scissors? ");
   scanf(" %c", &userInput);

   switch ((rand() % 3) + 1) {
      case 1:
      computerOut = 'r';
      strcpy(computerOutString, "rock");
      break;

      case 2:
      computerOut = 'p';
      strcpy(computerOutString, "paper");
      break;

      case 3:
      computerOut = 's';
      strcpy(computerOutString, "scissor");
      break;

      default:
      printf("Something went wrong.\n");
   }

   if (userInput == 'r' || userInput == 'p' || userInput == 's') {
      if (userInput == computerOut) {
         printf("I rolled %s. We tie!\n", computerOutString);
      }
      else if (computerOut == 'r') {
         if (userInput == 'p') {
            printf("I rolled %s. You win!\n", computerOutString);
         }
         else {
            printf("I rolled %s. You lose!\n", computerOutString);
         }
      }
      else if (computerOut == 'p') {
         if (userInput == 's') {
            printf("I rolled %s. You win!\n", computerOutString);
         }
         else {
            printf("I rolled %s. You lose!\n", computerOutString);
         }
      }
      else if (computerOut == 's') {
         if (userInput == 'r') {
            printf("I rolled %s. You win!\n", computerOutString);
         }
         else {
            printf("I rolled %s. You lose!\n", computerOutString);
         }
      }
   }
   else {
      printf("Error: you did not enter \'r\', \'p\', or \'s\'!\n");
   }

  return 0;
}
