#ifndef EVACRUNNER_H
  #define EVACRUNNER_H

#include <iostream> // for NULL

using namespace std;

class Road
{
public:
  int destinationCityID;
  int peoplePerHour;
  int ID;
}; // class Road

class Road2
{
public:
  int destinationCityID;
  int sourceCityID;
  int peoplePerHour;
  int peopleThisHour;
  Road2():peopleThisHour(0){}
}; //class Road2

class City
{
public:
  int ID;
  int x;
  int y;
  int population;
  int evacuees;
  Road *roads;
  int roadCount;

  City() : evacuees(0), roads(NULL), roadCount(0){}
  ~City(){delete [] roads;}
}; // class City

class EvacRoute
{
public:
  int roadID;
  int time;
  int numPeople;
  bool operator< (const EvacRoute &rhs) const;
}; // EvacRoute;

#endif
