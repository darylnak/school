//
// Created by Daryl on 6/14/17.
//

#ifndef FINAL_H1_WEIGHTEDEXERCISE_H
#define FINAL_H1_WEIGHTEDEXERCISE_H

#include "exercise.h"

class WeightedExercise : public Exercise
{
  int weight;

public:
  WeightedExercise(const string n, int r, int w) : Exercise(n, r), weight(w){} // Weighted exercise constructor (standard)
  ~WeightedExercise() {} // destructor

  void print(){cout << left << setw(20) << getName() << " "
                    << getReps() << " " << weight;}
  // print weighted exercise information.
};

#endif //FINAL_H1_WEIGHTEDEXERCISE_H
