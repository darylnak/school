#include <iostream>

#include "routines.h"

int main() {
  Routines routines; // Hold exercise routine of people
  string name; // get person name.
  ifstream inf("routines.csv");

  inf >> routines; // insert all routines in the map (map contained within routine)
  cout << "Name (0 = Done): "; // print prompt
  getline(cin, name); // get choice name

  while(name != "0") // while user did not enter 0
  {
    routines.display(name); // display the routine of person (name)
    cout << "Name (0 = Done): "; // display prompt
    getline(cin, name); // get name
  } // while

  return 0;
}