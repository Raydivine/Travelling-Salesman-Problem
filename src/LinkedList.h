#ifndef LinkedList_H
#define LinkedList_H
#include "CityCoordinate.h"

City *cityListNew(City *city);
void clearCityList(City *cities);
void addCityList(City **cities, City *city);

#endif // LinkedList_H