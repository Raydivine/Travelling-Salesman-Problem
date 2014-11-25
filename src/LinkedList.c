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

void reverseLinkedList(City *cities){
  City  *p = NULL , *q = cities, *r = q->next;

  q->next = p;
  p = q;
  q = r;

}

// static void reverse(struct node** head_ref)
// {
    // struct node* prev   = NULL;
    // struct node* current = *head_ref;
    // struct node* next;
    // while (current != NULL)
    // {
        // next  = current->next;
        // current->next = prev;
        // prev = current;
        // current = next;
    // }
    // *head_ref = prev;
// }

  // City *curCities = cities , *nxtCities;
  // cities = NULL;

  // while(curCities != NULL){
    // nxtCities = curCities->next;
    // curCities->next = cities;
    // cities = curCities;
    // curCities = nxtCities;
  // }

// void reverse() {
   //curNode traverses the list, first is reset to empty list.
    // struct node *curNode = first, *nxtNode;
    // first = NULL;

  // Until no more in list, insert current before first and advance.
    // while (curNode != NULL) {
    //   Need to save next node since we're changing the current.
        // nxtNode = curNode->link;

   //    Insert at start of new list.
        // curNode->link = first;
        // first = curNode;

     //  Advance to next.
        // curNode = nxtNode;
    // }
// }