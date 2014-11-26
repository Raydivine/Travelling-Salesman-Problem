#ifndef LinkedList_H
#define LinkedList_H
#include "CityCoordinate.h"

City *cityListNew(City *city);
void clearCityList(City *cities);
void addCityList(City **cities, City *city);
void reverseLinkedList(City *cities);
void reverseTheLinkBetween2City( City *cities, City *targetA, City *targetB);

#endif // LinkedList_H