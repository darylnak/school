#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;


class Road
{
public:
  int destinationCityID;
  int peoplePerHour;
  int ID;
};

class City
{
public:
  int ID;
  int x;
  int y;
  int population;
  Road *roads;
  int roadCount;
  bool evac;
  City(int I, int x2, int y2, int pop) : ID(I), x(x2), y(y2), population(pop),
    roads(NULL), roadCount(0), evac(false){}
  ~City(){delete [] roads;}
};

City*** createCities(int numCities, int &totalPopulation)
{
  int x, y, population, side = numCities / 2;
  City *** cities = new City**[side];

  totalPopulation = 0;

  for(int i = 0; i < side; i++)
  {
    cities[i] = new City*[side];
    for(int j = 0; j < side; j++)
      cities[i][j] = NULL;
  }

  for(int i = 0; i < numCities; i++)
  {
    do
    {
      x = rand() % side;
      y = rand() % side;

    } while(cities[x][y]);

    totalPopulation += population = 0x100000 / ((rand() & 0xFF) + 1);  // range 1048576 - 4096;
    cities[x][y] = new City(i, x, y, population);
  }

  return cities;
}  // createCities()


bool checkSegment(City ***cities, int lastX, int lastY, int startX, int endX,
  int startY, int endY, int &ID)
{
  int i, x, y, roadCount, lastRoadCount;

  for(x = startX; x < endX; x++)
    for(y = startY; y < endY; y++)
      if(cities[x][y])
      {
        for(i = 0; i < cities[x][y]->roadCount; i++)
          if(cities[x][y]->roads[i].destinationCityID == cities[lastX][lastY]->ID)
             break;
        if(i == cities[x][y]->roadCount) // unconnected city
        {
          lastRoadCount = cities[lastX][lastY]->roadCount++;
          Road *lastTemp = new Road[lastRoadCount + 1];
          for(int j = 0; j < lastRoadCount; j++)
            lastTemp[j] = cities[lastX][lastY]->roads[j];

          delete [] cities[lastX][lastY]->roads;
          cities[lastX][lastY]->roads = lastTemp;

          roadCount = cities[x][y]->roadCount++;
          Road *temp = new Road[roadCount + 1];
          for(int j = 0; j < roadCount; j++)
            temp[j] = cities[x][y]->roads[j];

          delete [] cities[x][y]->roads;
          cities[x][y]->roads = temp;

          temp[roadCount].peoplePerHour = lastTemp[lastRoadCount].peoplePerHour
            = (cities[x][y]->population + cities[lastX][lastY]->population) /(rand() % 100 + 50);
          lastTemp[lastRoadCount].destinationCityID = cities[x][y]->ID;
          temp[roadCount].destinationCityID = cities[lastX][lastY]->ID;
          temp[roadCount].ID = ID++;
          lastTemp[lastRoadCount].ID = ID++;
          return true;
        }
      } // if found a city

  return false;
} // checkSegment()


void createRoads(City ***cities, int numCities, int numRoads)
{
  int x = 0, y = 0, i, lastX, lastY, side = numCities / 2, ID = 0;
  int lastRoadCount, roadCount;
  Road *lastTemp, *temp;

  while(cities[x][y] == NULL) // find first city
    if(++x == side)
    {
      x = 0;
      y++;
    }

  for(i = 0; i < numCities - 1; i++) // make sure all cities are connected.
  {
    lastX = x;
    lastY = y;

    do
    {
      if(++x == side)
      {
        x = 0;
        y++;
      }
    } while(!cities[x][y]); // find next city

    lastRoadCount = cities[lastX][lastY]->roadCount++;
    lastTemp = new Road[lastRoadCount + 1];
    for(int j = 0; j < lastRoadCount; j++)    // copy old array to new array
      lastTemp[j] = cities[lastX][lastY]->roads[j];

    if(cities[lastX][lastY]->roads)
      delete [] cities[lastX][lastY]->roads;

    cities[lastX][lastY]->roads = lastTemp;

    roadCount = cities[x][y]->roadCount++;
    temp = new Road[roadCount + 1];
    for(int j = 0; j < roadCount; j++)
      temp[j] = cities[x][y]->roads[j];

    if(cities[x][y]->roads)
      delete [] cities[x][y]->roads;
    cities[x][y]->roads = temp;
    temp[roadCount].peoplePerHour = lastTemp[lastRoadCount].peoplePerHour
      = (cities[x][y]->population + cities[lastX][lastY]->population)
        /(rand() % 100 + 50); // range 50 to 150
    lastTemp[lastRoadCount].destinationCityID = cities[x][y]->ID;
    temp[roadCount].destinationCityID = cities[lastX][lastY]->ID;
    temp[roadCount].ID = ID++;
    lastTemp[lastRoadCount].ID = ID++;
  } // for i

   for(; i < numRoads; i++) // create the balance of the roads.
  {
    lastX = rand() % side;
    lastY = rand() % side;
    bool found = false;
    while(!cities[lastX][lastY]) // find next city
      if(++lastX == side)
      {
        lastX = 0;
        if(++lastY == side)
          lastY = 0;
      }

    for(int j = 1; !found && j < side; j++)
    {

      int startX = lastX - j;
      if(startX < 0)
        startX = 0;
      int endX = lastX + j + 1;
      if(endX > side)
        endX = side;
      int startY = lastY - j;
      if(startY < 0)
        startY = 0;
      int endY = lastY + j + 1;
      if(endY > side)
        endY = side;

      if(startY != lastY) // check top line
        found = checkSegment(cities, lastX, lastY, startX, endX, startY,
          startY + 1, ID);

      if(!found && endY - 1 != lastY) // check bottom line
        found = checkSegment(cities, lastX, lastY, startX, endX, endY - 1, endY,
          ID);
      if(!found && startX != lastX) // check left line
        found = checkSegment(cities, lastX, lastY, startX, startX + 1, startY,
          endY, ID);
      if(!found && endX - 1 != lastX) // check right line
        found = checkSegment(cities, lastX, lastY, endX - 1, endX, startY, endY,
          ID);

    } // for j
  } // for i
}

void writeCities(const char *filename, City ***cities, int numCities,
  int numRoads, int *evacIDs, int numEvacs)
{
  int side = numCities / 2;

  ofstream outf(filename);

  outf << numCities << ' ' << numRoads << ' ' << numEvacs << endl;
  for(int i = 0; i < numEvacs; i++)
    outf << evacIDs[i] << ' ';

  outf << endl;

  for(int x = 0; x < side; x++)
    for(int y = 0; y < side; y++)
      if(cities[x][y] != NULL)
      {
        City *temp = cities[x][y];
        outf << temp->ID << ' ' << temp->x << ' ' << temp->y << ' '
          << temp->population << ' ' << temp->roadCount << ' ';
        for(int i = 0; i < temp->roadCount; i++)
          outf << temp->roads[i].destinationCityID << ' '
          << temp->roads[i].peoplePerHour << ' ' << temp->roads[i].ID << ' ';
        outf << endl;
        delete temp;
      }  // if city exists

}

void  createEvac(int *evacIDs, int &numEvac, int numCities, City ***cities,
  int totalPopulation)
{
  int j, evacPopulation = 0, centerX, centerY, startX, endX, startY, endY,
     side = numCities / 2;

  totalPopulation /= 10;  // 10% evacuated
  numEvac = 0;
  j = 0;
  centerX = rand() % side;
  centerY = rand() % side;

  while(evacPopulation < totalPopulation)
  {
    startX = centerX - j;
    if(startX < 0)
      startX = 0;
    endX = centerX + j + 1;
    if(endX > side)
        endX = side;
    startY = centerY - j;
    if(startY < 0)
     startY = 0;
    endY = centerY + j + 1;
    if(endY > side)
        endY = side;

    for(int x = startX; x < endX; x++)
      for(int y = startY; y < endY; y++)
        if(cities[x][y] && !cities[x][y]->evac && evacPopulation < totalPopulation)
        {
          evacPopulation += cities[x][y]->population;
          evacIDs[numEvac++] = cities[x][y]->ID;
          cities[x][y]->evac = true;
        }
    j++;
  } // while evacPopulation < 10% of total Population


} // createEvac

int main(int argc, char* argv[])
{
  int seed, numCities, numRoads, numEvac, *evacIDs, totalPopulation;
  char filename[80];
  City *** cities;
  cout << "Cities: ";
  cin >> numCities;

  do {
    cout << "Roads: ";
    cin >> numRoads;
  } while(numRoads < numCities);

  cout << "Seed: ";
  cin >> seed;
  srand(seed);
  cities = createCities(numCities, totalPopulation);
  evacIDs = new int[numCities];
  createRoads(cities, numCities, numRoads);
  createEvac(evacIDs, numEvac, numCities, cities, totalPopulation);
  sprintf(filename, "cities-%d-%d-%d.txt", numCities, numRoads, seed);
  writeCities(filename, cities, numCities, numRoads, evacIDs, numEvac);
  delete [] evacIDs;
  for(int i = 0; i < numCities/2; i++)
    delete [] cities[i];
  delete [] cities;
  return 0;
}

