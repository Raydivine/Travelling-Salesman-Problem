#include "Travel.h"
#include <malloc.h>
#include <math.h>
#include "InitCity.h"
#include "CityCoordinate.h"
#include <stdio.h>
#include <stdlib.h>

City **createPathOfCityVisit(int numOfCities){
  City **cities = malloc(sizeof(City**) * numOfCities);
  City  *city   = *cities;
  return cities;
}

Path *createArrayOfPath(int numOfPath){
  Path *paths = malloc(sizeof(Path*) * numOfPath);
  return paths;
}


//-------------------------------------------------Sorting Function-----------------------------------------------------------------
float compare(void *v1, void *v2){
	float *A = (float *)v1;
	float *B = (float *)v2;
	return *A>*B ? 1 : *A<=*B ? -1 : 0; // A>b then return 1, A<=B then return -1, default is return 0
}

void swap(void *array, int index1, int index2){
	Path temp;
	Path *PathArray = (Path *)array;
	temp= PathArray[index2];
	PathArray[index2] = PathArray[index1];
	PathArray[index1] = temp;
}

Path genericBubbleSort(void *table, int size){
  int i,j;
   for (i = 1; i < size; i++) {
      for (j = 0; j < size - 1; j++) {
        
        
         }
      }
}
//---------------------------------------------------------------------------------------------------------------------------------------

// Cartesian formula
float findDistance(City *first, City *second){
  float  x,y, powX, powY, ans, rounded;

  x    = (*second).x_axis - (*first).x_axis;
  y    = (*second).y_axis - (*first).y_axis;
  powX = x*x;
  powY = y*y;
  ans  = sqrt(powX + powY);

  return ((int)(ans * 1000 + .5) / 1000.0); // correct number to 3 significant
}

Path formPathFromCities(City **cities, int size){
  int   i;
  float distance, rounded, totalDistance = 0;
  Path  path;

  for(i=0; i<size; i++){
    distance = findDistance( &(*cities[i]), &(*cities[i+1]));
    totalDistance = totalDistance + distance;
    printf("distance:  %f\n", distance);
  }
  printf("%Total   : %f\n", totalDistance);
  rounded = ((int)(totalDistance * 1000 + .5) / 1000.0); // correct number to 3 significant
  path = setPath(path,rounded,cities,size);
  return path;
}

Path formNewPath(Path path){
// printf("distance:  %f\n", path.distance);
// printf(" %d\n", path.cities[0]->ID);
// printf(" %d\n", path.cities[1]->ID);
// printf(" %d\n", path.cities[2]->ID);
// printf(" %d\n", path.cities[3]->ID);
// printf(" %d\n", path.cities[4]->ID);
// printf(" %d\n", path.cities[5]->ID);
}