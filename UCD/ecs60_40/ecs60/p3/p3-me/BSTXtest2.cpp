
#include <iostream>
#include "BSTX.h"
using namespace std;

int main()
{
  int i;
  BinarySearchTreeX<int> tree(-1);
  short values[] = {                         50, 
	           25,                                          75, 
	   15,             35,                         60,                90, 
       10,     20,     30,     40,                55,       65,      80,       95,  // full	
    5,      17,  22, 28, 32, 38, 42,           51,  57,   62, 67, 77,   85,  93, 99,
   2, 7,                             44,
  1,                               43,  45,
	                                  46};
	 
  for(i = 0; i < sizeof(values) / sizeof(short); i++)
    tree.insert(values[i]);
  cout << "Height: " << tree.height() << endl;
  cout << "Sum: " << tree.sum() << endl;
  
  if(tree.isAncestor(46, 25))
    cout << "25 is an ancestor of 46\n";
  else
    cout << "25 is not an ancestor of 46\n";

  if(tree.isAncestor(1, 35))
    cout << "35 is an ancestor of 1\n";
  else
    cout << "35 is not an ancestor of 1\n";

  cout << "Highest Full: " << tree.highestFull() << endl;
  cout << "Deepest Full: " << tree.deepestFull() << endl;
  return 0;
} // main())
