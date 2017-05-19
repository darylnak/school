#include <iostream>
#include "static.h"

using namespace std;

int Static::hello = 0;

int main()
{
  //cout << "hello";
  cout << ++Static::hello << endl;
}
