#include <cstdlib>
#include "evac.h"
#include "EvacRunner.h"

using namespace std;

int City3Cmp(const void *ptr, const void *ptr2)
{
  if( ((City3*) ptr)->ratio > ((City3*) ptr2)->ratio)
    return -1;
  else
    if( ((City3*) ptr)->ratio < ((City3*) ptr2)-> ratio)
      return 1;
    else
      return 0;
} // City3Cmp()

Evac::Evac(City *citie, int numCitie, int numRoads)
  : numCities(numCitie), depth(10)
{
  int ID, roadID, roadCount;
  cities = new City2[numCities];
  roads = new Road3[numRoads * 2];
  usedIDs = new int[numRoads * 2];

  for(int i = 0; i < numCitie; i++)
  {
    ID = citie[i].ID;
    cities[ID].evacuees = 0;
    cities[ID].population = citie[i].population;
    cities[ID].roadCount = roadCount = citie[i].roadCount;
    cities[ID].roadIDs = new int[roadCount];
    cities[ID].roadCapacity = 0;
    for(int j = 0; j < roadCount; j++)
    {
      cities[ID].roadIDs[j] = roadID = citie[i].roads[j].ID;
      roads[roadID].destinationCityID = (unsigned short) citie[i].roads[j].destinationCityID;
      roads[roadID].peoplePerHour =  citie[i].roads[j].peoplePerHour;
    } // for each road
  }
} // Evac()

void Evac::eliminateRoadsToEvacuatedCities()
{
  for(int i = 0; i < numCities; i++)
    if(!cities[i].known) // non-evacuated city
    {
      int j = 0;
      while(j < cities[i].roadCount)
      {
        int roadID = cities[i].roadIDs[j];
        if(cities[roads[roadID].destinationCityID].known) // an evacuated city
          cities[i].roadIDs[j] = cities[i].roadIDs[--cities[i].roadCount];
        else
        {
          cities[i].roadCapacity += roads[roadID].peoplePerHour;
          j++;
        }
      } // while
      if(cities[i].roadCapacity > cities[i].population)
        cities[i].roadCapacity = cities[i].population;
    }  // if non-evacuated city
    else
      cities[i].roadCapacity = cities[i].population;
}  // elminateRoadsto EvacuatedCities


void Evac::evacuate(int *evacIDs, int numEvacs, EvacRoute *evacRoutes,
    int &routeCount)
{
  int ID, roadID, flow, flowNeeded;
  time = 1;
  routeCount = 0;
  evacArray = new City3[numEvacs];
  queue = new unsigned short[numCities];
  front = back = 0;
  bool left = true;

  for(int i = 0; i < numEvacs; i++)
  {
    ID = evacIDs[i];
    cities[ID].known = true;
    cities[ID].end = false;
    cities[ID].evacuatedCity = true;
    cities[ID].depth = 1;
    queue[back++] = ID;
    evacArray[i].ID = ID;
  }

  eliminateRoadsToEvacuatedCities();
  processQ();
  left = processEvacsArray(evacArray, numEvacs);

  while(left)
  {
    usedCount = 0;
    for(int i = 0; i < numEvacs; i++)
    {
      int cityID = evacArray[i].ID;
      int total = 0;
      int needed = cities[cityID].population - cities[cityID].evacuees;

      for(int i = 0; i < cities[cityID].roadCount && total < needed; i++)
      {
        roadID = cities[cityID].roadIDs[i];
        if(roads[roadID].visitedCount > depth)
          continue;
        usedIDs[usedCount++] = roadID;
        roads[roadID].visitedCount++;
        flowNeeded = roads[roadID].peoplePerHour - roads[roadID].used;
        if(flowNeeded > needed - total)
          flowNeeded = needed - total;
        roads[roadID].visited = true;
        flow = dfs(roads[roadID].destinationCityID, flowNeeded, cityID);
        if(flow < flowNeeded)
          roads[roadID].visitedCount = 100;
        roads[roadID].visited = false;
        roads[roadID].used += flow;
        total += flow;
      }  // for each road
      cities[cityID].evacuees += total;
    } // for each evac city
    storeRoutes(evacRoutes, routeCount);
    time++;
    processQ();
    left = processEvacsArray(evacArray, numEvacs);
  }

} // evacuate


void Evac::storeRoutes(EvacRoute *evacRoutes, int &routeCount)
{
  int roadID;

  for(int i = 0; i < usedCount; i++)
  {
    roadID = usedIDs[i];
    roads[roadID].visitedCount = 0;

    if(roads[roadID].used != 0)
    {
      evacRoutes[routeCount].roadID = roadID;
      evacRoutes[routeCount].numPeople = roads[roadID].used;
      evacRoutes[routeCount++].time = time;
      roads[roadID].used = 0;
    }
  } // for each road used
}

int Evac::dfs(unsigned short cityID, int needed, unsigned short sourceCityID)
{
  int i, total = 0, roadID, flow, flowNeeded;

  if(!cities[cityID].evacuatedCity) // not an evacuated city
  {
    if(needed <= cities[cityID].population - cities[cityID].evacuees)
    {
      cities[cityID].evacuees += needed;
      return needed;
    }
    else // not enough room in city for needed
    {
      total = cities[cityID].population - cities[cityID].evacuees;
      cities[cityID].evacuees = cities[cityID].population;
    }
  } // if not an evacuated city then absorb some of the needed

  if(cities[cityID].end)
    return total;

  for(i = 0; i < cities[cityID].roadCount && total < needed; i++)
  {

    roadID = cities[cityID].roadIDs[i];
    if(roads[roadID].destinationCityID == sourceCityID || roads[roadID].visited)
      continue;  // no infinite loops!

    if(roads[roadID].visitedCount == 0)
      usedIDs[usedCount++] = roadID;

    if(++roads[roadID].visitedCount > depth)
      continue;
    flowNeeded = roads[roadID].peoplePerHour - roads[roadID].used;
    if(flowNeeded > needed - total)
      flowNeeded = needed - total;
    roads[roadID].visited = true; // prevent infinite loops
    flow = dfs(roads[roadID].destinationCityID, flowNeeded, cityID);
    if(flowNeeded > flow) // maxed out the city so don't use the road again
      roads[roadID].visitedCount = 100;
    roads[roadID].visited = false;

    roads[roadID].used += flow;
    total += flow;
  }
  return total;
} // dfs()

bool Evac::processEvacsArray(City3 *evacArray, int numEvacs)
{
  int capacity, ID, roadID;
  bool left = false;

  for(int i = 0; i < numEvacs; i++)
  {
    ID = evacArray[i].ID;
    if(cities[ID].evacuees < cities[ID].population)
    {
      left = true;
      capacity = 0;
      for(int j = 0; j < cities[ID].roadCount; j++)
      {
        roadID = cities[ID].roadIDs[j];
        if(roads[roadID].peoplePerHour <
          cities[roads[roadID].destinationCityID].roadCapacity)
          capacity += roads[roadID].peoplePerHour;
        else
          capacity += cities[roads[roadID].destinationCityID].roadCapacity;

      } // for j
        evacArray[i].ratio = (cities[ID].population - cities[ID].evacuees)
         / (1.0 * capacity);
    } // if some evacuees still left
    else
      evacArray[i].ratio = 0;
  } // for each city still in the evacArray

  if(left)
    qsort(evacArray, numEvacs, sizeof(City3), City3Cmp);

  return left;
} // processEvacsArray


void Evac::processQ()
{
  int back2 = back, ID, destCityID;
  for(int i = front; i < back; i++)
    cities[queue[i]].end = false;

  while(front < back2)
  {
    ID = queue[front++];

    for(int j = 0; j < cities[ID].roadCount;)
    {
      destCityID = roads[cities[ID].roadIDs[j]].destinationCityID;
      if(!cities[destCityID].known)
      {
        queue[back++] = destCityID;
        cities[ID].depth = time + 1;
        cities[destCityID].known = true;
      }

      if(cities[destCityID].depth != 0 && cities[destCityID].depth < time - 1)
      // more than one level back in tree so eliminate road
      {
        int temp = cities[ID].roadIDs[j];
        cities[ID].roadIDs[j] = cities[ID].roadIDs[--cities[ID].roadCount];
        cities[ID].roadIDs[cities[ID].roadCount] = temp;
      }

      else // city not in tree
        j++;
    } // for each road
  } // while more in the queue for this round

} // processQ()

