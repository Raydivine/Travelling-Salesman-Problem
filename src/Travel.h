#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance(City *first, City *second);
Path TotalDistanceCities (City cities[]);
City **createPathOfCityVisit(int numOfCities);

#endif // Travel_H
