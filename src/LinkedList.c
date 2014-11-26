#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>
#include "CityCoordinate.h"

LinkedList *linkListNew(City *cities){
  LinkedList *link = malloc(sizeof(LinkedList));
  link->next = NULL;
  link->cities = cities;
  return link;
}


void clearLinkedList(LinkedList *firstList){
  if(firstList->next)
    clearLinkedList(firstList->next);
  free(firstList);
}


void addLinkedList(LinkedList **listPtr, LinkedList *newList){
  LinkedList *head = *listPtr, *tail;

}