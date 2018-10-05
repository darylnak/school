#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
	char filename[80];
   int i, pos, count, seed;

   cout << "This program creates a series of integers randomly selected from a range.\n";
   
   cout << "Number of integers: ";
   cin >> count;
	cout << "Filename: ";
   cin  >> filename;
   cout << "Seed: ";
   cin >> seed;
   srand(seed);
   ofstream outf(filename);
   int *array = new int[count];
   for(i = 0; i < count; i++)
   	array[i] = i + 1;

   for(i = count - 1; i >= 0; --i)
   {
   	pos = rand() % (i + 1);
      outf << array[pos] << ' ';
      array[pos] = array[i];
   }

   outf.close();





}
