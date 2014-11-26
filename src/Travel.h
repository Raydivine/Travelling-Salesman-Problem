#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
City *cityListNew(City *cities);
void clearLinkedList(City *cities);
void getDistanceFromPath( Path path);
void genericBubbleSort ( Path table[], int size);
//City **createPathOfCityVisit( int numOfCities);


#endif // Travel_H
