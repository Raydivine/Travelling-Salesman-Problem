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

// Cartesian formula
float findDistance( City *first, City *second){
  float  x,y, powX, powY, ans, rounded;

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

Path MutationOfCities(Path path, City *targetA, City *targetB){
  City  *temp1 =  targetA->next , *temp2 =  targetB->next;

  reverseTheLinkBetween2City( path.cities, targetA, targetB);
  targetA->next = targetB;
  temp1->next   = temp2;

  path = getDistanceFromPath(path);
  return path;
}

int checkingFor2opt(City *targetA, City *targetB){
printf("%d\n",targetA->ID);
printf("%p\n",targetA->next);
printf("%p\n",targetB);
  // float oldLink = findDistance( targetA, targetA->next) ;//+ findDistance( targetB, targetB->next);
  // float newLink = findDistance( targetA, targetB) + findDistance( targetA->next, targetB->next);

}
// while(ptr != NULL)
// {
        // if(ptr->val == val)
        // {
            // found = true;
            // break;
        // }
        // else
        // {
            // ptr = ptr->next;
        // }
    // }


// Path formPathFromCities( City **cities, int size){
  // int   i;
  // float distance, rounded, totalDistance = 0;
  // Path  path;

  // for(i=0; i<size; i++){
    // distance = findDistance( &(*cities[i]), &(*cities[i+1]));
    // totalDistance = totalDistance + distance;
    // printf("distance:  %f\n", distance);
  // }
  // printf("%Total   : %f\n", totalDistance);
  // rounded = ((int)(totalDistance * 1000 + .5) / 1000.0); // correct number to 3 significant
  // setPath(&path,rounded,cities,size);
  // return path;
// }

// City **createPathOfCityVisit( int numOfCities){
  // City **cities = malloc(sizeof(City**) * numOfCities);
  // City  *city   = *cities;
  // return cities;
// }