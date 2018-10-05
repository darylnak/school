// Author: Sean Davis
#ifndef evacH
#define evacH

#include "QueueAr.h"
#include "EvacRunner.h"


class MyRoad
{
public:
  int ID;
  int destinationCityID;
  int sourceCityID;
  int peoplePerHour;

  MyRoad() : ID(0), destinationCityID(0), sourceCityID(0), peoplePerHour(0) {}
};

class MyCity
{

public:
  int ID;
  int population;
  int evacuees;
  int level;

  MyRoad* roads;
  int roadCount;

  MyCity() : ID(0), population(0), evacuees(0), level(0) {}

};

class Evac
{
private:
  int clock;

public:
  MyCity** cities;
  bool* wasVisited;
  bool* isEvacCity;
  int* roadCurrUsing;

  Queue<MyCity> bfs;
  int numCities;
  int totalRoads;
  int minFlow;
  int numPeopleLeft;

  Evac(City *cities, int numCities, int numRoads);
  void evacuate(int *evacIDs, int numEvacs, EvacRoute *er, int &routeCount); // student sets evacRoutes and routeCount
  int DFS(MyCity* origin, int originID, int given, EvacRoute* evacRoutes, int& routeCount);

  // for qsort()
  static int compareRoads (const void * a, const void * b);
  static int compareCity (const void * a, const void * b);
}; // class Evac

#endif