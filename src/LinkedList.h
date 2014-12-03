#ifndef LinkedList_H
#define LinkedList_H
#include "CityCoordinate.h"

City *cityListNew(City *city);
void clearCityList(City *cities);
void addCityList(City **cities, City *city);
void addCityListPrev(City **cities, City *city);
void reverseLinkedList(City *start, City *end);
void reverseTheLinkBetween2City( City *cities, City *start, City *end);

#endif // LinkedList_H