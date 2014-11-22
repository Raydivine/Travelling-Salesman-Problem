#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
City **createPathOfCityVisit( int numOfCities);
Path  *createArrayOfPath    ( int numOfPath  );
Path formPathFromCities( City **cities, int size);
Path genericBubbleSort ( Path   *table, int size);
Path formNewPath( Path path);

#endif // Travel_H
