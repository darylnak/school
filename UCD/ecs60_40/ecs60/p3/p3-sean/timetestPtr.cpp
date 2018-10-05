#include "CPUTimer.h"
#include <fstream>
#include <cstdlib>
#include "QuadraticProbingPtr.h"
using namespace std;
CPUTimer ct;


void RunQuadraticProbing(char *filename, int size)
{
  QuadraticPtrHashTable <int> hashTable(-1, size);
  ct.reset();
  ifstream inf(filename);
  char command, s[512];
  int i;

  inf.getline(s,512);

 while(inf >> command)
  {
    inf >> i;
    if (command == 'i')
    	hashTable.insert(i);
		else
			hashTable.remove(i);
  } //while
} // RunQuadraticProbing


int main(int argc, char *argv[])
{
  ct.reset();
  RunQuadraticProbing(argv[1], atoi(argv[2])); 
  cout << (int) (100 * ct.cur_CPUTime()) << endl;
  return 0;
}

