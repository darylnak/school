//
// Created by Daryl on 6/14/17.
//

#ifndef FINAL_H1_EXERCISE_H
#define FINAL_H1_EXERCISE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Exercise
{
  string name; // name of exercise
  int reps; // repetitions
public:
  Exercise(const string n, int r): name(n), reps(r){} // Standard constructor for exercise.
  virtual ~Exercise(){} // Destructor for exercise. Virtual because WeightedExercise is derived from the class.
  // Blank because not dynamic memory allocation.
  const string& getName()const{return name;} // get exercise name.
  int getReps()const {return reps;} // get repetitions.
  virtual void print() {cout << left << setw(20) << name.c_str() << " " << reps;}
  // print Exercise information.
}; // class Exercise

#endif //FINAL_H1_EXERCISE_H
