#include <fstream>
#include "pager.h"
#include "indexpager.h"

using namespace std;

int main(int argc, char* argv[])
{
  Pager pager, *ptr;
  IndexPager indexer;
  char c;
  ifstream inf(argv[1]);

  if(argv[2][0] == '1')
    ptr = &pager;
  else // else second argument is 2
    ptr = (Pager*) &indexer;

  ptr->read(inf);
  inf.close();
  ptr->processKey('b');  // Causes initial write

  do
  {
    cin >> c;
    ptr->processKey(c);
  } while (c != 'q');

  return 0;
} // main()
