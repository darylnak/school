#include "palindrome.h"

#include <stdbool.h>
#include <string.h>

// returns true if palindrome, else returns false.
bool IsPalindrome(char* line) {
   // fgets() will give a string that includes the new-line character. Therefore, string is longer than it should be. Take away 1 to compensate.
   int boundry = (strlen(line) - 1) / 2;

   /* here, I am taking away 2. Why? because I need to "rid" of the new line character, then I need to move back one to I don't access the array out of bounds. I could have done this in the if statement, but this improves readability a bit.
   */
   int length = (strlen(line) - 2);

   for (int i = 0; i < boundry; i++) {
      if (line[i] != line[length - i]) {
         return false;
      }
   }
   return true;
}

// returns the number of lines that are palindromes, given an array of string and the amount of strings.
int LinesWithPalindrome(char** lines, int numLines) {
   int result = 0;

   for (int i = 0; i < numLines; i++) {
      if (IsPalindrome(lines[i])) {
         ++result;
      }
   }
   return result;
}
