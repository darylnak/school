#ifndef _PALINDROME_H
#define _PALINDROME_H

#include <stdbool.h>

// returns true if palindrome, else returns false.
bool IsPalindrome(char* line);

// returns the number of lines that are palindromes, given an array of string and the amount of strings.
int LinesWithPalindrome(char** lines, int numLines);

#endif
