#ifndef MYSTRINGFUNCTIONS
#define MYSTRINGFUNCTIONS

#include <stdbool.h>

// Creates a new string from the first n chars of src
//
// Example:
// The result of deepCopyStr("great googly moogly", 6) is "great "
char* deepCopyStr(char* src, int n);

// Checks that the first n chars of src are lowercase letters or digits
//
// Example:
// The result of isLowerOrDigitStr("100timeS!", 7) is true
// The result of isLowerOrDigitStr("100timeS!", 8) is false
bool isLowerOrDigitStr(char* src, unsigned int n);

// Creates a new string from the first n chars of the
// concatenation of str1 and str2
//
// Example:
// The result of deepCopyStr("great", " googly moogly", 10) is "great goog"
char* concatStrs(char* str1, char* str2, int n);

#endif
