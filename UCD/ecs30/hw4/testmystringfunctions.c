#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Homework TODO: Include mystringfunctions.h here
#include "mystringfunctions.h"

// Homework TODO: Add function prototypes here
bool getAndRunTest();
void deepCopyStrTestA();
void deepCopyStrTestB();
void deepCopyStrTestC();
void isLowerOrDigitStrTestA();
void isLowerOrDigitStrTestB();
void isLowerOrDigitStrTestC();
void concatStrsTestA();
void concatStrsTestB();
void concatStrsTestC();
void flushStdin();

// Asks user to pick a unit test to run.
// In practice, we write unit tests using a unit testing framework
// and all unit tests are run when the code is compiled.
// For grading purposes, we ask the user to pick the test.
// DO NOT modify this function for your homework.
int main() {
   // User menu
   printf("Which unit test would you like to run?\n");
   printf("1) deepCopyStr\n");
   printf("\ta) n = 2, src = \"test string\"\n");
   printf("\tb) n = 0 returns \"\\0\"\n");
   printf("\tc) negative n returns NULL\n");
   printf("2) isLowerOrDigitStr\n");
   printf("\ta) n = 4, src = \"testString\"\n");
   printf("\tb) n = 5, src = \"testString\"\n");
   printf("\tc) n = 0\n");
   printf("3) concatStrs\n");
   printf("\ta) n = 5, str1 = \"test\", str2 = \"string\"\n");
   printf("\tb) n = 5, str1 = \"\", str2 = \"test string\" returns \"test \"\n");
   printf("\tc) n = 5, str1 = \"test\", str2 = \"\" returns NULL\n");
   while (!getAndRunTest()) {}

   return 0;
}

// Prompt user once for the test to run. 1a is deepCopyStrTestA,
// 1b is deepCopyStrTestB, 2c is isLowerOrDigitStrTestC, and so on.
// If the user input is valid, run the test and return true.
// If the user input is invalid, print the error according to the homework
// prompt and return false.
bool getAndRunTest() {
   // Homework TODO(COMPLETE): complete the code for this function.
   char userInput[3] = {'\0', '\0', '\0'};

   fgets(userInput, 3, stdin);
   flushStdin();

   if (userInput[0] == '1') {
      switch (userInput[1]) {
         case 'a':
         deepCopyStrTestA();
         return true;

         case 'b':
         deepCopyStrTestB();
         return true;

         case 'c':
         deepCopyStrTestC();
         return true;

         default:
         printf("Enter a, b, or c for the test case.\n");
         return false;
      }
   }
   else if (userInput[0] == '2') {
      switch (userInput[1]) {
         case 'a':
         isLowerOrDigitStrTestA();
         return true;

         case 'b':
         isLowerOrDigitStrTestB();
         return true;

         case 'c':
         isLowerOrDigitStrTestC();
         return true;

         default:
         printf("Enter a, b, or c for the test case.\n");
         return false;
      }
   }
   else if (userInput[0] == '3') {
      switch (userInput[1]) {
         case 'a':
         concatStrsTestA();
         return true;

         case 'b':
         concatStrsTestB();
         return true;

         case 'c':
         concatStrsTestC();
         return true;

         default:
         printf("Enter a, b, or c for the test case.\n");
         return false;
      }
   }
   else {
      printf("Enter 1, 2, or 3 for the function to test.\n");
      return false;
   }
}

// Test n = 2 and src = "test string" returns "te"
void deepCopyStrTestA() {
   char* result = deepCopyStr("test string", 2);
   // if (result) checks to see something is returned (even if the string is empty).
   //   We will see later in the course this is checking if the result is a NULL pointer
   assert(result && result[0] == 't' && result[1] == 'e' && result[2] == '\0');
   printf("Test successful.\n");
}

// Test n = 0 the returns "\0"
void deepCopyStrTestB() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   char* result = deepCopyStr("test string", 0);
   printf("%s", result);
   assert(result && result[0] == '\0');
   printf("Test successful.\n");
}

// Test negative n returns NULL"
void deepCopyStrTestC() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   char* result = deepCopyStr("test string", -1);

   assert(result == NULL);
   printf("Test successful.\n");
}

// Test n = 4, src = "testString" returns true
void isLowerOrDigitStrTestA() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   assert(isLowerOrDigitStr("testString", 4));
   printf("Test successful.\n");
}

// Test n = 5, src = "testString" returns false
void isLowerOrDigitStrTestB() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   assert(!isLowerOrDigitStr("testString", 5));
   printf("Test successful.\n");
}

// Test n = 0, src = "" returns true
void isLowerOrDigitStrTestC() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   assert(isLowerOrDigitStr("", 0));
   printf("Test successful.\n");
}

// Test n = 10, str1 = "test", str2 = "string" returns "teststring"
void concatStrsTestA() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   assert(strcmp(concatStrs("test", "string", 10), "teststring") == 0);
   printf("Test successful.\n");
}

// n = 5, str1 = "", str2 = "test string" returns "test "
void concatStrsTestB() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   assert(strcmp(concatStrs("", "test string", 5), "test ") == 0);
   printf("Test successful.\n");
}

// n = 5, str1 = "test", str2 = "" returns NULL
void concatStrsTestC() {
   // Homework TODO: write code for this test case according to the
   // specifications in the comment above the function.
   assert(concatStrs("test", "", 5) == NULL);
   printf("Test successful.\n");
}

// Flush stdin buffer
void flushStdin() {
   char c;
   // Skip all characters until end-of-file marker
   // or new line / carriage return
   while ( (c = getchar()) != EOF &&
   c != '\n' &&
   c != '\r' ) {};
}
