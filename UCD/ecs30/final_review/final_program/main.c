#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"
#define MAX_LEN 12

int main(int argc, char* argv[]) {
   char line[MAX_LEN];
   char* next;
   char* lines[200];
   int numLines = 0;

   if (argc != 2) {
      fprintf(stderr, "Error: this program takes only one argument, the name of
              a file to analyze.\n");
      return 0;
   }
   else {
      FILE* file = fopen(argv[1], "r");
      next = fgets(line, MAX_LEN, file);
      printf("%lu\n", strlen(next));
      while(next != NULL && atoi(next) != EOF) {
         lines[numLines] = malloc((strlen(line) + 1) * sizeof(char));
         strcpy(lines[numLines], line);
         next = fgets(line, MAX_LEN, file);
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
