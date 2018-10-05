#include "BST2.h"
#include <fstream>
#include <iostream>
using namespace std;


void RunBST(char *filename)
{
  BinarySearchTree <int> tree(-1);
  ifstream inf(filename);
  char command, s[512];
  int i, j;

  inf.getline(s,512);

 while(inf >> command >> i)
  {
    if (command == 'i')
      tree.insert(i);
    else if (command == 'd')
      tree.remove(i);
    else
    {
      inf >> j;
      tree.printRange(i,j);
    }
  } //while
} // RunBST()



int main()
{
  char filename[80];
  cout << "Filename >> ";
  cin >> filename;
  RunBST(filename); 
  return 0;
}

