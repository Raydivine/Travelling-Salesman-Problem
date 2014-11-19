#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance(City *first, City *second);
City **createPathOfCityVisit(int numOfCities);
Path formPathFromCities(City **cities, int size);

#endif // Travel_H
