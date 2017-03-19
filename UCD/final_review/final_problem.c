#include <stdio.h>

int main() {
  int x = 1, i = 1;
     for (i = 0; i < 6; i++) {
      x++;
      x *= 2;
    }
    printf("%d\n", x);
}
