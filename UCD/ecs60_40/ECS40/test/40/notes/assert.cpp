#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

#ifndef NDEBUG
#define assert2(x) if(!(x)) {cerr << __FILE__ << ":" << __LINE__ << ": Assertion '" << #x << "' failed.\n"; exit(1);} 
#else
#define assert2(x)
#endif

int main()
{
  int num = 0;
  assert(num != 0);
  return 0;
}
