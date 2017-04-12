#include <stdio.h>
#include <ctype.h>

int main(void) {

  int upperBound = 0;
  int lowerBound = 1;
  int numGuesses = 0;
  int currGuess  = 0;
  char lowHighOrEqual = '\0';

  printf("Enter n: ");
  if (scanf("%d", &upperBound) == 1 && upperBound >= 0) {
    currGuess = ((upperBound - lowerBound) / 2) + 1; //initial midpoint
    while ((upperBound - lowerBound) > 0) {

      printf("Is your number %d? ", currGuess);
      scanf(" %c", &lowHighOrEqual);

      if (lowHighOrEqual == 'e') {
        ++numGuesses;
        break;
      }
      else if (lowHighOrEqual == 'l') {
        if (upperBound == currGuess) {
          printf("Error: that's not possible.\n");
          return 0;
        }
        lowerBound = currGuess + 1;
        currGuess = lowerBound + ((upperBound - lowerBound) / 2.0);
      }
      else if (lowHighOrEqual == 's'){
        if (lowerBound == currGuess) {
          printf("Error: that's not possible.\n");
          return 0;
        }
        upperBound = currGuess - 1;
        currGuess = upperBound - ((upperBound - lowerBound) / 2.0);
      }
      else {
        printf("Error: invalid input.\n");
        return 0;
      }
      ++numGuesses;
    }
    printf("Your number must be %d. I used %d guesses.\n", currGuess, numGuesses);
  }
  else {
    if (isdigit(upperBound)) {
      printf("Error: n must be positive.\n");
    }
    else {
      printf("Error: invalid input.\n");
    }
  }

  return 0;
}
