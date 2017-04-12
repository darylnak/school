#include <stdio.h>

int main(int argc, char const *argv[]) {

  int test = 0;
  char myChar = '\0';
// notice that SPECIFICALLY FOR CHARS the newline character is read. Therefore, unless I flush stdin or inlcude a space in the second scanf() statment, I will not be prompted for a second input!
  scanf("%d", &test);
  scanf("%c", &myChar);
  return 0;
}
