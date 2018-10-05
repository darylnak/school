#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
  int a = 25, b = 228;
  printf("%08d%-7dJ\n", a, b);
  cout << setw(8) << setfill('0') << a << left << setw(7) << setfill(' ')  << b << 'J' << endl;
  return 0;
} // main()
