#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

City **createPathOfCityVisit(int numOfCities);
Path *createArrayOfPath(int numOfPath);
float findDistance(City *first, City *second);
Path formPathFromCities(City **cities, int size);
Path formNewPath(Path path);
Path genericBubbleSort(void *table, int size);

#endif // Travel_H
