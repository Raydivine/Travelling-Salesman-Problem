#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance(City *first, City *second);
//float findDistance(City first, City second);
Path *TotalDistanceCities (City **cities, int arraySize);
City **createPathOfCityVisit(int numOfCities);

#endif // Travel_H
