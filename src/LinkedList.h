#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;

struct LinkedList {
  LinkedList *next;
  void *data;
};

LinkedList *linkListNew(void *data);
void addLinkedList(LinkedList **listPtr, LinkedList *newList);
void destroyAllLinkedLists(LinkedList *firstList);
#endif // LinkedList_H