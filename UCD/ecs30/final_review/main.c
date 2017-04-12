#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char* argv[]) {

   char line[801];
   char* lines[200];
   int numLines = 0;
   int result = 0;
   char* next;

   if (argc != 2) {
      printf("Error: this program takes only one argument, the name of a file to analyze.\n");
      return 0;
   }
   else {
      FILE* file = fopen(argv[1], "r");
      lines[numLines] = malloc(200 * sizeof(char*));
      next = fgets(line, 801, file);
      if (file != NULL) {
         while (!feof(file)) {
            lines[numLines] = malloc((strlen(line) + 1) * sizeof(char));
            strcpy(lines[numLines], line);
            printf("%s\n", line);
            next = fgets(line, 801, file);
            ++numLines;
         }
         result = LinesWithPalindrome(lines, numLines);
      }
      fclose(file);
   }
   printf("Result: %d\n", result);
   for (int i = 0; i < numLines; i++) {
      free(lines[i]);
   }
   free(lines);

   return 0;
}
