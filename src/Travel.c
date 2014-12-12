#include "Travel.h"
#include "unity.h"
#include <malloc.h>
#include <math.h>
#include "InitCity.h"
#include "CityCoordinate.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void bubbleSortForPath( Path table[], int size){
  int i,j;
  Path temp;

  for (i = 1; i < size; i++){
    for (j = 0; j < size - 1; j++) {
      if( table[j].distance >table[j+1].distance ){
        temp= table[j+1];
        table[j+1] = table[j];
        table[j] = temp;
      }
    }
  }
}

void bubbleSortForNeighBour( NeighBour route[], int size){
  int i,j;
  NeighBour temp;

  for (i = 1; i < size; i++){
    for (j = 0; j < size - 1; j++) {
      if( route[j].distance >route[j+1].distance ){
        temp= route[j+1];
        route[j+1] = route[j];
        route[j] = temp;
      }
    }
  }
}

float findDistance( City *first, City *second){
  float  x,y, powX, powY, ans, rounded;
  // Cartesian formula
  x    = (*second).x_axis - (*first).x_axis;
  y    = (*second).y_axis - (*first).y_axis;
  powX = x*x;
  powY = y*y;
  ans  = sqrt(powX + powY);

  return ((int)(ans * 1000 + .5) / 1000.0); // correct number to 3 significant
}

Path getDistanceFromPath( Path path){
  City *cities = path.cities, *cityNext;
  int   headID = cities->ID;
  float TotalDistance  = 0;

  TotalDistance = findDistance( cities,cities->next);
  cityNext = cities->next;
  int size = 1;

  while(cityNext->ID != headID){
    TotalDistance = TotalDistance + findDistance( cityNext, cityNext->next);
    cityNext = cityNext->next;
    size = size + 1;
  }

  path.size     = size ;
  path.distance = TotalDistance;

  return path;
}

Path MutationCities(Path path, City *targetA, City *targetB){
  if(targetA->ID == targetB->ID)
    return;

  City  *temp1 =  targetA->next , *temp2 =  targetB->next;

  reverseTheLinkBetween2City( path.cities, targetA, targetB);
  targetA->next = targetB;
  temp1->next   = temp2;

  path = getDistanceFromPath(path);
  return path;
}

Path copyPath (Path path){
  City *cities = path.cities, *cloneCities, city[path.size];
  int i;
  Path clonePath;

  for(i=0; i<path.size; i++){
   city[i] = *cities;
   cities = cities->next;
   cloneCities = &city[i];
   cloneCities = cloneCities->next;
  }
  clonePath.cities   = cloneCities;
  clonePath.size     = path.size;
  clonePath.distance = path.distance;

  return clonePath;
}

City copyCity ( City city){
  City clone;
  clone.x_axis = city.x_axis ;
  clone.y_axis = city.y_axis;
  clone.ID     = city.ID;
  clone.next   = NULL;
  return clone;
}

int checkingFor2opt(City *targetA, City *targetB){
  if(targetA->ID == targetB->ID)
    return 0;

  float oldLink = findDistance( targetA, targetA->next) + findDistance( targetB, targetB->next);
  float newLink = findDistance( targetA, targetB) + findDistance( targetA->next, targetB->next);

  if(newLink < oldLink)
    return 1;
  return 0;
}

City getFrontCity(City *cities, City target){
  City frontCity, *front;

  if(cities->ID == target.ID)
    cities = cities->next;

  while(cities->next->ID != target.ID)
    cities = cities->next;
  frontCity = copyCity(*cities);
  return frontCity;
}

City getBackCity(City *cities, City target){
  City backCity, *back;

  while(cities->ID != target.ID)
    cities = cities->next;
  backCity = copyCity(*cities->next);
  return backCity;
}

int checkIsCityNotUsed( City arr[], City target, int range){
  int i;

  for(i = 0 ; i < range ; i ++){
    if( arr[i].ID == target.ID)
      return 0;
  }
  return 1;
}

void addCityToBack (City arr[], City target, int range, int endID){
  int i;

  for(i = 0 ; i < range ; i ++){
    if(arr[i].ID == endID){
      arr[i+1] = target;
      break;
    }
  }
}

void addCityToFront(City arr[], City target, int range){
  int i;
  City arr2[range];

  for(i = 0 ; i < range; i ++)
    arr2[i+1] = arr[i];
  arr2[0] = target;
  for(i= 0; i < range; i ++)
    arr[i] = arr2[i];
}

Path convertArrayToPath( City arr[], int range){
  int i;
  Path path;
  City *cities;

  arr[0].next = NULL;
  cities =  cityListNew(&arr[0]);
  City *head = cities;

  for(i = 1 ; i < range; i ++){
    arr[i].next = NULL;
    addCityList(&cities, &arr[i]);
  }
  addCityList(&cities, head);

  path.cities = cities;
  return path;
}

void addCityOfNeighBour (City arr[], City lastCityInArr, City *cities, int stop, int range){
  NeighBour near[range];
  int i = 0 , sizeNear = 0;
  
  while(cities->ID != stop){
    if(checkIsCityNotUsed( arr, *cities, range)){
      near[i].neighBour = copyCity(*cities);
      sizeNear = sizeNear + 1;
      i++;
    }
    cities = cities->next;
  }
  
  for (i = 0; i < sizeNear ; i++)
    near[i].distance = findDistance( &lastCityInArr, &near[i].neighBour);
    
  bubbleSortForNeighBour( near, sizeNear);
  
  for (i = 0; i < sizeNear ; i++){
    addCityToBack (arr, near[i].neighBour, range, lastCityInArr.ID);
    lastCityInArr = near[i].neighBour;
  }
}

Path crossoverCities(Path path1, Path path2, City target){
  int range = path1.size, i;
  City *head1 = path1.cities, *head2 = path2.cities, arr[range], front, back, lastCityInArr;
  Path path;

  arr[0] = target;
  lastCityInArr = arr[0];
  
  while(head1->ID != target.ID)
    head1 = head1->next;
  while(head2->ID != target.ID)
    head2 = head2->next;

  front = getFrontCity(head1, target);
  back  = getBackCity (head2, target);

  while(checkIsCityNotUsed( arr, front, range)){
    addCityToFront(arr, front, range);
    front = getFrontCity(head1, front);

    if(checkIsCityNotUsed( arr, back, range)){
      addCityToBack (arr, back, range, lastCityInArr.ID);
      lastCityInArr = back;
      back = getBackCity(head2, back);
    } else
        break;
  }

  head1 = head1->next;
  addCityOfNeighBour( arr, lastCityInArr, head1, target.ID, range);
  
  
  path = convertArrayToPath(arr, range);
  
// printf("%d\n",path.cities->ID);
// printf("%d\n",path.cities->next->ID);
// printf("%d\n",path.cities->next->next->ID);
// printf("%d\n",path.cities->next->next->next->ID);
// printf("%d\n",path.cities->next->next->next->next->ID);
// printf("%d\n",path.cities->next->next->next->next->next->ID);
// printf("%d\n",path.cities->next->next->next->next->next->next->ID);
// printf("%d\n",path.cities->next->next->next->next->next->next->next->ID);
// printf("%d\n",path.cities->next->next->next->next->next->next->next->next->ID);
// printf("%d\n",path.cities->next->next->next->next->next->next->next->next->next->ID);
  return path;
}

Path travelInShortestPath (City arr[]){

}


  // printf("%d\n",rand()%50);
  // printf("%d\n",rand()%50);
  // printf("%d\n",rand()%50);
  // printf("%d\n",rand()%50);
  // printf("%d\n",rand()%50);

  
  // printf("%f\n", path.distance);
// printf("%d\n",crossCities->ID);
// printf("%d\n",crossCities->next->ID);
// printf("%d\n",crossCities->next->next->ID);
// printf("%d\n",crossCities->next->next->next->ID);
// printf("%d\n",crossCities->next->next->next->next->ID);
// printf("%d\n",crossCities->next->next->next->next->next->ID);
// printf("%d\n",crossCities->next->next->next->next->next->next->ID);
// printf("%d\n",crossCities->next->next->next->next->next->next->next->ID);
// printf("%d\n",crossCities->next->next->next->next->next->next->next->next->ID);
// printf("%d\n",crossCities->next->next->next->next->next->next->next->next->next->ID);


  // printf("%d\n",endID);
  // printf("%d\n",arr[0].ID);
  // printf("%d\n",arr[1].ID);
  // printf("%d\n",arr[2].ID);
  // printf("%d\n",arr[3].ID);
  // printf("%d\n",arr[4].ID);
  // printf("%d\n",arr[5].ID);
  // printf("%d\n",arr[6].ID);
  // printf("%d\n",arr[7].ID);
  // printf("%d\n",front.ID);
  // printf("%d\n",back.ID);


    //printf("%p\n",newWalk);
   // printf("%p\n",ptrBack);
   // printf("%p\n",newWalk);
   // printf("%p\n",newWalk->next);


  // if(checkIsTargetNotInCities( newWalk, target2) ){
     // *ptrBack = copyCity(*ptrBack, target2);
     // ptrBack = ptrBack->next;
  // }
  // back  = getBackCity (cities2nd, target2);


     // printf("%d\n",newWalk->ID);
    // printf("%d\n",newWalk->next->ID);
    // printf("%d\n",newWalk->next->next->ID);

  // printf("%p\n",newWalk);
  // printf("%p\n",newWalk->next);
  // printf("%p\n",newWalk->next->next);
     // printf("%d\n",ptrBack->ID);
      // printf("%p\n",ptrBack);


// printf("%d\n",cloneCities->ID);
// printf("%d\n",cloneCities->next->ID);
// printf("%d\n",cloneCities->next->next->ID);
// printf("%d\n",cloneCities->next->next->next->ID);
// printf("%d\n",cloneCities->next->next->next->next->ID);
// printf("%d\n",cloneCities->next->next->next->next->next->ID);
// printf("%d\n",cloneCities->next->next->next->next->next->next->ID);
// printf("%d\n",cloneCities->next->next->next->next->next->next->next->ID);


// printf("%p\n",cities1st);
// printf("%p\n",cities1st->next);
// printf("%p\n",cities1st->next->next);
// printf("%p\n",cities1st->next->next->next);
// printf("%p\n",cities1st->next->next->next->next);
// printf("%p\n",cities1st->next->next->next->next->next);
// printf("%p\n",cities1st->next->next->next->next->next->next);
// printf("%p\n",cities1st->next->next->next->next->next->next->next);
// printf("%p\n",cities1st->next->next->next->next->next->next->next->next);

// Path crossoverCities(Path path1, Path path2, City target){

  // int range = path1.size, i, end = target.ID;
  // City *head1 = path1.cities, *head2 = path2.cities, arr[range], front, back, *crossCities;
  // Path path;

  // arr[0] = target;
  // while(head1->ID != target.ID)
    // head1 = head1->next;
  // while(head2->ID != target.ID)
    // head2 = head2->next;

  // front = getFrontCity(head1, target);
  // back = getBackCity(head2, target);

  // while(checkIsCityNotUsed( arr, front, range)){
    // addCityToFront(arr, front, range);
    // front = getFrontCity(head1, front);

    // if(checkIsCityNotUsed( arr, back, range)){
      // addCityToBack (arr, back, range, end);
      // end = back.ID;
      // back = getBackCity(head2, back);
    // } else
        // break;
  // }

  // head1 = head1->next;
  // addRestOfCities ( arr, head1, target.ID, end, range);

  // arr[0].next = NULL;
  // crossCities =  cityListNew(&arr[0]);
  // City *point = crossCities;

  // for(i = 1 ; i < range; i ++){
    // arr[i].next = NULL;
    // addCityList(&crossCities, &arr[i]);
  // }
  // addCityList(&crossCities, point);

  // path.cities = crossCities;
  // return path;
// }


