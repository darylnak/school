#include <stdio.h>

int main() {

  int myArray[5] = {0, 0, 0, 0, 0};
  int temp = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%d", &myArray[i]);
  }

  printf("Current Array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", myArray[i]);
  }

  for (int i = 0; i < 5 / 2; i++) {
    temp = myArray[i];
    myArray[i] = myArray[4 - i];
    myArray[4 - i] = temp;
  }
  printf("\n");
  printf("Reversed Array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");
}
