#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"
#include "CityCoordinate.h"
#include "InitCity.h"

City *cityListNew(City *city){
  City *cities = malloc(sizeof(City));
  cities->ID     = city->ID;
  cities->x_axis = city->x_axis;
  cities->y_axis = city->y_axis;
  cities->next   = NULL;
  return cities;
}

void clearCityList(City *cities){
  free(cities);
}

void addCityList(City **cities, City *city){
  City *head = *cities, *tail;

  if(head == NULL){
    cities  = &city;
    return;
  }
  tail = head;

  while(tail->next != NULL)
    tail = tail->next;
  tail->next = city;
}

void reverseLinkedList(City *start, City *end){
  City *curCities = start , *nxtCities;
  start = NULL;

  while(curCities != NULL){
    nxtCities = curCities->next;
    curCities->next = start;
    start = curCities;
    curCities = nxtCities;
  }
}

void reverseTheLinkBetween2City( City *cities, City *start, City *end){

  while(cities != start)
    cities = cities->next; 
    
  City *curCities = cities->next , *nxtCities, *stop = end->next;
  start = NULL;

  while(curCities != stop){
    nxtCities = curCities->next;
    curCities->next = start;
    start = curCities;
    curCities = nxtCities;
  }
}




























