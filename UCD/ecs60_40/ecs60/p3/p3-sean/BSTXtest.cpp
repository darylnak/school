
#include <iostream>
#include "BSTX.h"
using namespace std;

/*  The tree

                                10
               5                                15
       0             6                    12                    20   // full
-5        2              8                   14          16           22    
             4                                              18             24
                                                                              26

 */

int main()
{
  int i;
  BinarySearchTreeX<int> tree(-1);

  for(i = 10; i <= 20; i += 5)
  {
    tree.insert(i);
    tree.insert(15 - i);
  }
  for(i = 2; i < 28; i += 2)
    if(i % 5 != 0)
      tree.insert(i);
  cout << "Height: " << tree.height() << endl;
  cout << "Sum: " << tree.sum() << endl;
  
  if(tree.isAncestor(4,5))
    cout << "5 is an ancestor of 4\n";
  else
    cout << "5 is not an ancestor of 4\n";

  if(tree.isAncestor(5,4))
    cout << "4 is an ancestor of 5\n";
  else
    cout << "4 is not an ancestor of 5\n";

  cout << "Highest Full: " << tree.highestFull() << endl;
  cout << "Deepest Full: " << tree.deepestFull() << endl;
  return 0;
} // main())
