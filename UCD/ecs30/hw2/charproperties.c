#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

  char userInput;

  printf("Please enter a character: ");
  scanf("%c", &userInput);

  if (isalpha(userInput) > 0) {

    if (isupper(userInput) > 0) {
      printf("The char is an uppercase letter.\n");
    }
    else {
      printf("The char is a lowercase letter.\n");
    }

    switch (userInput) {
      case 'A':
      case 'a':
      case 'B':
      case 'b':
      case 'C':
      case 'c':
      case 'E':
      case 'e':
      case 'I':
      case 'i':
      case 'O':
      case 'o':
      case 'U':
      case 'u':

      printf("The char is a vowel.\n");
      break;
    }
  }

  if (isdigit(userInput) > 0) {
    printf("The char is a digit.\n");
  }
  if (ispunct(userInput) > 0) {
    printf("The char is punctuation.\n");
  }
  if (userInput == '\t') {
    printf("The char is a tab.\n");
  }
  if (userInput == '\"') {
    printf("The char is a double quote\n");
  }

  return 0;
}
