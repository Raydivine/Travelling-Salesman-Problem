#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"
#include "CityCoordinate.h"
#include "InitCity.h"

City *cityListNew(City *city){
  City *cities   = malloc(sizeof(City));
  cities         = city;
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

void reverseTheLinkBetween2City( City *cities, City *start, City *end){
  if(start->ID == end->ID)
    return ;
    
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