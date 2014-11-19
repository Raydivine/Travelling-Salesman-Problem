#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance(City *first, City *second);
City **createPathOfCityVisit(int numOfCities);
Path TotalDistanceCities (City **cities, int size);

#endif // Travel_H
