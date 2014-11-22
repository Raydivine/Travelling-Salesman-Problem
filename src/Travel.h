#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

void bubbleSort(float iarr[], int num);
Path genericBubbleSort(void *table, int size, int(*comapare(void*,void*)));
float findDistance(City *first, City *second);
City **createPathOfCityVisit(int numOfCities);
Path formPathFromCities(City **cities, int size);
Path formNewPath(Path path);

#endif // Travel_H
