#include <stdio.h>
#include <math.h> // ONLY HAS MATH OPERATIONS FOR FLOATS! Use stdlib.h for some INTEGER math operations!!
#include <stdlib.h>


int main(int argc, char const *argv[]) {

  int hey, test
  ,      hello; // ok because whitespaces ignored (spaces, new lines, and anything that creates space without visual characters)

  int heyThere; //lowerCamel case - think sitting on camel eith hump in front

  int identifier = 1; //declare/define variable of type int, named/identified as identifier, and initialize/assign it the value of zero at it's memeory location.

  int divideByZeroError = 10 / identifier; // causes a runtime error and program will terminate if identifier is 0 - identifier is 0; cannot divide by zero.

  divideByZeroError = 10 % identifier; // causes a runtime error and program will terminate f identifier is 0 - identifier is 0; cannot divide by zero.

  char myString[50] = "";
  double sometimesZero = 0.0;
  double divideByZeroFloatError = 1.0 / sometimesZero; // will result in postive infinity if sometimes zero is 0.0. Negative infinity if were -0.0 (negative).

  const double GRAVITY_ACCELERATION = 9.8; // use const when I want an unchanging literal.

  double sciNotation = 6.02e23; // can use scientific notation and will output as decimal

  printf("sciNotation: %lf\n", sciNotation);
  printf("%d\n", atoi("4"));
  printf("%lf\n", divideByZeroFloatError); // return the string as an integer if the string is actually a valid integer. Otherwise, will return 0. Good: "42" | Bad: 42w

  printf("%c\n", myString); //even though myString is a single character, this is an error because I specified printf to print a char
  scanf("%s", &myString);
  scanf("%s", &myString);
  scanf("%c", &myString);

  // common escape sequences: \n, \t, \\, \', \"

  // scanf() only reads up until the first white space. Having two successive scanf() statements, omitting the space in the second scanf(), when the user type "Fuji Apple"<enter>, will result in the first scanf() reading "Fuji" and the second reading "Apple" - Notice how I don't get the second chance to type again. If I included a third scanf(), <enter>/\n would have been "typed" had there been no space in the beggining of the third scanf() and the format string was for a character. If it had a format string for strings, this would not cascade and I would still be prompted for input.

  // When using scanf on after the other, don't forget the space in the beggining of the second scanf to indicate I want ignore whitespaces - pressing enter is a new line character, hence I also entered a char with a whitespace, causing weird shit.

  // When dealing with string, you cannot assign values to a string using '=' unless you are initializing it. I must use strcpy(dest, src) and dest mu be as large as src (don't forget about the null terminator/character, so actually length of src + 1).

  // Must include <string.h> for string functions.

  // unsigned ints allocates all maximum bits of numbers to the postive portion. If we want to print/scan an unsigned value, use the format specifier %u, %lu, %llu accordingly.

  // relational and equality operators should only be used on ints, characters. Floating points numbers are imprecise and strings have specific functions to do this.

  // charatcer types return value. Does not quit is already converted or not a logical type - tolower('?');

  // conditional expression: (condition) ? expr1 : expr2;

  enum LightState {RED, YELLOW, GREEN};

  enum LightState currLight = RED;

  // enum is a set of constant values for a new type. In this case LightState. Anything with a type enum LightState may only take on these values. The values are indexed as numbers starting from 0.

  /* psuedo code for swapping elements from two arrays
  arr 1 2 3 4
  arr2 5 6 7 8
  int temp

  for < numElem

  temp = arr[i]
  arr[i] = arr2[i]
  arr2[i] = temp
 */

// initialize a 2D array. Make mental note of the nested braces. In this form, it is easy to see 3 rows and 4 columns.

// When doing anything withchar arrays/string, always remember the null character is at the end. Therefore, I must stop when I reach it. Otherwise, weird shit will happen -- trying to access memory I "don't have". If I forget about the null character, the compiler will continue unitl it reaches one.

// When using scanf() for strings, whitespaces are ignored.

// fgets(dest, num_to_read, stdin (FILE* fp))
   // if less than num_to_read, new line will be copied to dest, then null character will be appended. If larger, num_to_read - 1 will be stored and null character will be appended. This functions still takes into account that null character must exist in dest to be proper. In general, fgets() will read the new line character so long as I do not have a string >= num_to_read. Commonly, I will iterate through the string until I find '\n', then replace it with '\0'.

   // here is something really exciting. Since I know about 2D arrays and C Strings, I can do something very clever. That is, create an array of strings using theses two concepts together. Here is an example: char myStrings[50][75];. This is hold 50 strings that can be 75 cahacters long (including the null character). To access a string, do: myString[i], where i is the i'th string.

   //assert is a greate testbench/ test harness for unit testing. I must first #include <assert.h> to use asser(). To use this functions, do this: assert(MyFunction == expression);. Basically, I am checking for the success or failure of that function. I know what it should return, so I am checking. If it succeeded, i.e. returns an expected value, the expression will evaulate to true/1, and the program will continue. If the test fails/returns an unexpected value, the expression will evaluaute to false, causing assert() to stop the program and print the entire line, the function it was in, and the line number of the assert. The entire expression will be shown too.

   // Remember this! Since parameters are local variables to a function, we can technically assign values to them during function calls. However, this is considered bad practice and lazy. Why? because it is confusing to read. We may use the value of the parameters later in the code, but not it has been changed! Everything will go to shit. I don't want that. Instead, create a local variable within the function and assign the value of the parameters to that instead. This will increase program readability and reduce the probability of error.

   // When passing an array to a function, doing int mayArr[] implies an array pointer will be passed. When passing an array, prepending & is not neccesary as arrays are passed by reference automatically. Further, if in the parameters of a functions we include 'const', e.g MyFunct(const int myArr[]) {...}, we are telling the compiler and others that we are not modifying the array, but looking at it's value or whatever.

 int my2DArray[3][4] = {
    {1, 1, 1, 1},
    {2, 2, 2, 2},
    {3, 3, 3, 3},
};
  return 0;
}
