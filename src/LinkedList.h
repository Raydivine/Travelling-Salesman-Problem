#ifndef LinkedList_H
#define LinkedList_H
#include "CityCoordinate.h"

typedef struct LinkedList LinkedList;

struct LinkedList {
  LinkedList *next;
  City *cities;
};

LinkedList *linkListNew(City *cities);
void addLinkedList(LinkedList **listPtr, LinkedList *newList);
void clearLinkedList(LinkedList *firstList);
#endif // LinkedList_H