//
// Created by Daryl on 6/14/17.
//

#ifndef FINAL_H2_FATTYFOOD_H
#define FINAL_H2_FATTYFOOD_H

#include <iostream>
#include <map>
#include "Food.h"

using namespace std;

class FattyFood : public Food // Derived from Food. Store information about fat content.
{
  double fat; // Fat amount (decimal to tenths place)

public:
  ~FattyFood(){} // FattyFood destructor
  FattyFood(const FattyFood& ff) : Food(ff.getName(), ff.getCal(), ff.getFib()), fat(ff.fat)
  {
    // copy contructor. Used to create pointer.
  }
  FattyFood(const string name = "", int c = 0, int fi = 0, double fa = 0.0) : Food(name, c, fi), fat(fa){} // default and standard constructor.
  friend istream& operator>>(istream& is, FattyFood& ff) // retrieve information about fatty food.
  {
    int cal; // store amount of calories
    int fi; // store amount of fiber
    double fa; // store amount of fat.
    string name; // store food name.

    is >> cal >> fi >> fa >> name; // get relative information about fatty foods.

    FattyFood temp(name, cal, fi, fa);
    // create temp FattyFood (call constructor) and assign it to FattyFood in main()
    // (what is actually going to bet inserted.
    ff = temp; // assign FattyFood in main(). Why? Because I do not have access to private information in Food.

    return is; // return stream.
  }
  void print() const // displat relative information about FattyFood.
  {
    cout << getCal() << " calories, " << getFib() << "g fiber, "
         << fat << "g saturated fat." << endl; // print universal information.
    // print relative information about FattyFood.
  }
};

#endif //FINAL_H2_FATTYFOOD_H
