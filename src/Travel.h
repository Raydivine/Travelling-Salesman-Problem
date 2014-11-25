#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
Path getDistanceFromPath( Path path);
void genericBubbleSort ( Path table[], int size);
City *cityListNew(City *cities);
void clearCityList(City *cities);
//City **createPathOfCityVisit( int numOfCities);


#endif // Travel_H
