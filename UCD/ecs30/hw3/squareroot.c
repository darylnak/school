#include <stdio.h>

int main(void) {

  int userInt = 0;
  int userGuess = 0;
  int numSteps = 0;
  double currApprox = 0.0;

  printf("Enter the integer you wish to find the square root of: ");
  scanf("%d", &userInt);

  printf("Enter your first guess and number of steps: ");
  scanf("%d", &userGuess);
  scanf(" %d", &numSteps);

  currApprox = userGuess;

  for (int i = 0; i < numSteps; ++i) {
    currApprox = 0.5 * (currApprox + (userInt / currApprox));
  }

  printf("The square root of %d is approximately %.5lf", userInt, currApprox);

  return 0;
}
