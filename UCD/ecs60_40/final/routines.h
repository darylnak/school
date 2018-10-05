//
// Created by Daryl on 6/14/17.
//

#ifndef FINAL_H1_ROUTINES_H
#define FINAL_H1_ROUTINES_H

#include <fstream>
#include <map>
#include "weightedexercise.h"

using namespace std;

class Routines
{
  multimap<string, Exercise*> routineMap; // routine map

public:
  ~Routines(){ // delete all pointers when program exits.
    for(multimap<string, Exercise*>::const_iterator itr = routineMap.begin(); itr != routineMap.end(); itr++)
      delete itr->second;
    // start at beginning of map and work your way to the end, deleting all Exercise pointers along the way.
  }
  friend istream& operator>>(istream& is, Routines& rout) // get routines and insert into map.
  {
    string name, line; // store person name (name) and information about routine/routine name (line).
    char comma; // Hold comma for weighted. Used to check if non-weighted (will hold something other than ',' ('\n')).
    int numEx, rep, weight = 0; // store number of exercises, repetitions, and potential weight.

    while(getline(is, name, ','))
    {
      is >> numEx; // get number of exercises.
      getline(is, line); // clear new line. IMPORTANT

      for(int i = 0; i < numEx; i++) // read appropriate amount of exercises
      {
        getline(is, line, ','); // get exercise name
        is >> rep; // get repetition amount.
        is.get(comma); // get, potentially, comma ('\n' if end of line - non-weighted).
        if(comma == ',') // check if non-weighted (will be '\n' if true)
          is >> weight; // Weighted! So store weight information.

        if(weight > 0) // if weight
        {
          rout.routineMap.insert(multimap<string,
          Exercise *>::value_type(name, new WeightedExercise(line, rep, weight))); // insert WeightedExercise into map.
          getline(is, line); // clear new line (do not need to non-weight because I already grabbed it)
        }
        else // non-weighted
        {
          rout.routineMap.insert(multimap<string,
          Exercise *>::value_type(name, new Exercise(line, rep))); // insert Exercise into map
        }

        weight = 0; // reset weight check.
      }
    } // get next name if present.

    return is; // return stream
  }

  void display(string& n) // display routine information about person (name)
  {
    // Get lower and upper bound of person in map (get all routine information about person)
    for(multimap<string, Exercise*>::const_iterator itr = routineMap.lower_bound(n); itr != routineMap.upper_bound(n); itr++)
    {
      itr->second->print(); // print relative exercise information information
      cout << endl; // print new line after getting relative information about exercise.
    }
  }
};

#endif //FINAL_H1_ROUTINES_H
