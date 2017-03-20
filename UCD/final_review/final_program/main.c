#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char* argv[]) {
   char line[12];
   char* next;
   char* lines[200];
   int numLines = 0;

   if (argc != 2) {
      fprintf(stderr, "Error: this program takes only one argument, the name of a file to analyze.\n");
      return 0;
   }
   else {
      FILE* file = fopen(argv[1], "r");
      next = fgets(line, 12, file);
      while(next != NULL && atoi(next) != EOF) {
         lines[numLines] = malloc(strlen(line) * sizeof(char));
         strcpy(lines[numLines], line);
         next = fgets(line, 12, file);
         ++numLines;
      }
      printf ("Number of Palindromes: %d\n", LinesWithPalindrome(lines, numLines));
      fclose(file);
      for (int i = 0; i < numLines; i++) {
         free(lines[i]);
      }
   }
   return 0;
}
