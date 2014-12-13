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

Path MutationCities(Path path, City targetA, City targetB){
  if(targetA.ID == targetB.ID)
    return;
  City  *tourA =  path.cities , *tourB = path.cities;

  while(tourA->ID != targetA.ID)
    tourA = tourA->next;
  while(tourB->ID != targetB.ID)
    tourB = tourB->next;
  City  *temp1 =  tourA->next , *temp2 = tourB->next;
  
  reverseTheLinkBetween2City( path.cities, tourA, tourB);
  tourA->next = tourB;
  temp1->next = temp2;

  path = getDistanceFromPath(path);
  return path;
}

int checkingFor2opt(City *cities, City targetA, City targetB){
  if(targetA.ID == targetB.ID)
    return 0;
    
  City *pointA = cities;
  City *pointB = cities;

  while(pointA->ID != targetA.ID)
    pointA = pointA->next;
  while(pointB->ID != targetB.ID)
    pointB = pointB->next;

  float oldLink = findDistance( pointA, pointA->next) + findDistance( pointB, pointB->next);
  float newLink = findDistance( pointA, pointB) + findDistance( pointA->next, pointB->next);

  if(newLink < oldLink)
    return 1;
  return 0;
}

City copyCity ( City city){
  City clone;
  clone.x_axis = city.x_axis;;
  clone.y_axis = city.y_axis;
  clone.ID     = city.ID;
  clone.next   = NULL;
  return clone;
}

Path copyPath (Path path, City arr[]){
  int i, size = path.size , stop;
  City *cities = path.cities, *newCites, *cloneCities , head;
  Path newPath;
  stop = cities->ID;

  for( i = 0; i < size ; i ++){
    arr[i] = *cities;
    cities = cities->next;
  }

  newPath = convertArrayToPath( arr,  size);
  newPath.size     = path.size;
  newPath.distance = path.distance;
  return newPath;
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
      arr[i+1] = copyCity(target);
      break;
    }
  }
}

void addCityToFront(City arr[], City target, int range){
  int i;
  City arr2[range];

  for(i = 0 ; i < range; i ++)
    arr2[i+1] = arr[i];
  arr2[0] = copyCity(target);
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

void addCityOfNeighbour(City arr[], City lastCityInArr, City *cities, int stop, int range){
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

Path crossoverCities(Path path1, Path path2, City target, City arr[]){
  int range = path1.size, i;
  City *head1 = path1.cities, *head2 = path2.cities, front, back, lastCityInArr;
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
    } else break;
  }
  head1 = head1->next;
  addCityOfNeighbour( arr, lastCityInArr, head1, target.ID, range);
  
  path = convertArrayToPath(arr, range);
  path = getDistanceFromPath(path);
  return path;
}

City *getRandomCity ( City *cities, City random){
  while(cities->ID != random.ID)
    cities = cities->next;
  return cities;
}

void clearCityArray(City arr[], int size){
  int i;
  City empty; 
       empty.x_axis = 0;
       empty.y_axis = 0;
       empty.ID = 0;
  for(i = 0 ; i<size; i++ )
    arr[i] = empty; 
}

void copyArray( City clone[], City arr[], int size){
  int i;
  for(i=0 ; i < size ; i++){
    clone[i] = arr[i];
  }
}

// rake test:Travel
Path travelInShortestPath( City arr[], int size){
  City rand1, rand2, rand3, arr1[size], arr2[size], comb[size];
  Path best, better, combine;
  copyArray( arr1, arr, size);
  copyArray( arr2, arr, size);
  best  = convertArrayToPath( arr1, size);
  best  = getDistanceFromPath( best);
  better = copyPath ( best, arr2);
 
  int i, counter = 0;
  printf("Original distance :%f\n", best.distance);
  while (counter < size){
    do{ rand1 = arr[rand()%size];
        rand2 = arr[rand()%size];
    }while( rand1.ID == rand2.ID);

    if( checkingFor2opt( best.cities, rand1, rand2)){
      best = MutationCities( best, rand1, rand2);
      counter = 0;
    }else counter = counter + 1;

    rand3 = arr[rand()%size];
    combine = crossoverCities(best , better, rand3, comb);
   
    if( combine.distance < best.distance && combine.distance < better.distance){    
      better = copyPath ( best, arr2);
      best   = copyPath ( combine, arr1);  
      counter = 0;
    }else counter = counter + 1;
    
    clearCityArray(comb, size);
  }

  return best;
}

// printf("1 better: %d\n",better.cities->ID);
// printf("2 better: %d\n",better.cities->next->ID);
// printf("3 better: %d\n",better.cities->next->next->ID);
// printf("4 better: %d\n",better.cities->next->next->next->ID);
// printf("5 better: %d\n",better.cities->next->next->next->next->ID);
// printf("6 better: %d\n",better.cities->next->next->next->next->next->ID);
// printf("7 better: %d\n",better.cities->next->next->next->next->next->next->ID);
// printf("8 better: %d\n",better.cities->next->next->next->next->next->next->next->ID);
// printf("9 better: %d\n",better.cities->next->next->next->next->next->next->next->next->ID);
// printf("10 better: %d\n",better.cities->next->next->next->next->next->next->next->next->next->ID);
// printf("11 better: %d\n",better.cities->next->next->next->next->next->next->next->next->next->next->ID);
// printf("1 best: %d\n",best.cities->ID);
// printf("2 best: %d\n",best.cities->next->ID);
// printf("3 best: %d\n",best.cities->next->next->ID);
// printf("4 best: %d\n",best.cities->next->next->next->ID);
// printf("5 best: %d\n",best.cities->next->next->next->next->ID);
// printf("6 best: %d\n",best.cities->next->next->next->next->next->ID);
// printf("7 best: %d\n",best.cities->next->next->next->next->next->next->ID);
// printf("8 best: %d\n",best.cities->next->next->next->next->next->next->next->ID);
// printf("9 best: %d\n",best.cities->next->next->next->next->next->next->next->next->ID);
// printf("10 best: %d\n",best.cities->next->next->next->next->next->next->next->next->next->ID);
// printf("10 best: %d\n",best.cities->next->next->next->next->next->next->next->next->next->next->ID);
// printf("1 comb: %d\n",comb[0].ID);
// printf("2 comb: %d\n",comb[1].ID);
// printf("3 comb: %d\n",comb[2].ID);
// printf("4 comb: %d\n",comb[3].ID);
// printf("5 comb: %d\n",comb[4].ID);
// printf("6 comb: %d\n",comb[5].ID);
// printf("7 comb: %d\n",comb[6].ID);
// printf("8 comb: %d\n",comb[7].ID);  
// printf("9 comb: %d\n",comb[8].ID);  
// printf("10 comb: %d\n",comb[9].ID);  

// printf("1 combine :%d\n",combine.cities->ID);
// printf("2 combine :%d\n",combine.cities->next->ID);
// printf("3 combine :%d\n",combine.cities->next->next->ID);
// printf("4 combine :%d\n",combine.cities->next->next->next->ID);
// printf("5 combine :%d\n",combine.cities->next->next->next->next->ID);
// printf("6 combine :%d\n",combine.cities->next->next->next->next->next->ID);
// printf("7 combine :%d\n",combine.cities->next->next->next->next->next->next->ID);
// printf("8 combine :%d\n",combine.cities->next->next->next->next->next->next->next->ID);
// printf("9 combine :%d\n",combine.cities->next->next->next->next->next->next->next->next->ID);
// printf("10 combine :%d\n",combine.cities->next->next->next->next->next->next->next->next->next->ID);
// printf("11 combine :%d\n",combine.cities->next->next->next->next->next->next->next->next->next->next->ID);


