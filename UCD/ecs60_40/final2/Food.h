//
// Created by Daryl on 6/14/17.
//

#ifndef FINAL_H2_FOOD_H
#define FINAL_H2_FOOD_H

#include <string>
#include <iostream>

using namespace std;

class Food // Store universal information about food.
{
  string name; // name of Food
  int calories; // calories
  int fiber; // fiber

public:
  virtual ~Food(){} // Food destructor. Empty; not dynamic allocation
  Food(const Food& f) : name(f.name), calories(f.calories), fiber(f.fiber) {} // copy constructor. Used to make pointer for map.
  Food(const string n = "", int c = 0, int fi = 0) : name(n), calories(c), fiber(fi){} // default and standard constructor
  const string& getName() const {return name;} // get food name
  void display() const // print relative food information. Virtual because two types of food.
  {
    print(); // call print for universal information
  }
  virtual void print() const // print universal information about food.
  {
    cout << calories << " calories, " << fiber << "g fiber, and no fat." << endl; // print universal information.
  }
  const int getCal() const {return calories;} // get calories
  const int getFib() const {return fiber;} // get fiber
  friend istream& operator>>(istream& is, Food& f) // read in a regular food item
  {
    int cal; // store amount of calories
    int fi; // store amount of fiber
    string name; // store food name

    is >> cal >> fi >> name; // retrieve relative info

    f.name = name; // assign name
    f.calories = cal; // assign calories amount
    f.fiber = fi; // assign fiber amount

    return is; // return stream.
  }
};

#endif //FINAL_H2_FOOD_H
