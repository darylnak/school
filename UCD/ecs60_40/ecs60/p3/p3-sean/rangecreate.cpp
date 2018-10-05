#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  int i, j , x, y;

   cout << "File creation program \n";
   ofstream outf("PR1.dat");
   outf << "Has a series of 20 insertions in order from 0 to 19 followed by 5 deletions 15 to 20, followed by 5 range requests\n";
   for(i = 0; i < 20; i++)
        outf << "i" << i << " ";
   for(i = 19; i >= 15; i--)
        outf << "d" << i << " ";
   for(i = 7, j = 8; i > 2; i--, j++)  
     outf << "r" << i << " " << j << " ";
   outf.close();

   outf.open("PR2.dat");
   outf << "Has a series of 20 random insertions from 0 to 99 followed by 10 random range requests\n";
   srand(1);

   for(i = 20; i > 0; i--)
   {
     int value = rand() % 100; 
     outf << "i" << value << " ";
   } // for i

   for(int i = 0; i < 10; i++)
   {
     x = rand() % 100;
     y = rand() % 100;
     outf << "r" << x <<  " " << y << " ";
   } // for i

   outf.close();

  return 0;
}


