#include <stdio.h>

int main(int argc, char const *argv[]) {
  char myName[10];
  char myChar = '\0';
  int age = 0;

  fscanf(stdin, "%s", myName);
  fscanf(stdin, "%d", &age);
  fscanf(stdin, "%c", &myChar);
  return 0;
}
