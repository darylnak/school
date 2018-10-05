#include <iostream>

#include <fstream>
#include "FattyFood.h"

using namespace std;
typedef multimap<string, Food*> FoodMap;

void read(istream& is, FoodMap& map);

int main()
{
  string choice; // capture choice
  FoodMap fmap; // map for food name and dietary information
  ifstream inf("food.txt"); // open food.txt

  read(inf, fmap); // populate map with food and dietary information

  do{ // Keep getting choice until Done
    cout << "Food (Done to end): "; // print prompt
    cin >> choice; // get choice

    if (choice != "Done") // Do only if not Done
    {
      if (fmap.find(choice) != fmap.end()) // if food exists
        fmap.find(choice)->second->display(); // print information

      else // does not exist
        cout << "Name not found.\n"; // print error.
    }
  } while(choice != "Done"); // while not Done

  for(FoodMap::const_iterator itr = fmap.begin(); itr != fmap.end(); itr++) // delete pointers in map
    delete itr->second;
}

void read(istream& is, FoodMap& map) // populate map with food and dietary information
{
  FattyFood fattyFood; // Hold FattyFood - derivative
  Food food; // Hold Food - Base
  char choice; // capture tye of food


  while(is >> choice) // while there is food to insert
  {
    if(choice == 'F') //  if fatty food
    {
      is >> fattyFood; // insert info into fattyfood
      map.insert(FoodMap::value_type(fattyFood.getName(), new FattyFood(fattyFood))); // insert fatty food into map
    }
    else // regular food - no fat
    {
      is >> food; // insert info into food
      map.insert(FoodMap::value_type(food.getName(), new Food(food))); // insert food into map
    }
  }
}