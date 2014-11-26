#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>

LinkedList *linkListNew(void *data){
  LinkedList *link = malloc(sizeof(LinkedList));
  link->next = NULL;
  link->data = data;
  return link;
}


void destroyAllLinkedLists(LinkedList *firstList){
  if(firstList->next)
    destroyAllLinkedLists(firstList->next);
  free(firstList);
}


void addLinkedList(LinkedList **listPtr, LinkedList *newList){
  LinkedList *head = *listPtr, *tail;

}