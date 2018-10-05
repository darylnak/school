// Author: Sean Davis
#ifndef evacH
#define evacH

#include "EvacRunner.h"

class City2
{
public:
  bool known;
  bool end;
  bool evacuatedCity;
  int *roadIDs;
  int population;
  int evacuees;
  char roadCount;
  int depth;
  int roadCapacity;
  City2():known(false), end(true), evacuatedCity(false), evacuees(0)
  {}
}; // City2 class


class City3
{
public:
  unsigned short ID;
  float ratio;
}; // City3 class


class Road3
{
public:
  char visitedCount;
  bool visited;
  unsigned short destinationCityID;
  int peoplePerHour;
  int used;
  Road3(): visitedCount(0), visited(false), used(0) {}
}; // Road3 class

class Evac
{
  City2 *cities;
  Road3 *roads;
  int numCities;
  City3 *evacArray;
  int time;
  unsigned short *queue;
  int back;
  int front;
  int usedCount;
  int *usedIDs;
  int depth;
  void eliminateRoadsToEvacuatedCities();
  void processQ();
  bool processEvacsArray(City3 *evacArray, int numEvacs);
  int dfs(unsigned short cityID, int needed, unsigned short sourceCityID);
  void storeRoutes(EvacRoute *evacRoutes, int &routeCount);

public:
  Evac(City *cities, int numCities, int numRoads);
  void evacuate(int *evacIDs, int numEvacs, EvacRoute *evacRoutes,
    int &routeCount); // student sets evacRoutes and routeCount

}; // class Evac



#endif
