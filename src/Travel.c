#include "Travel.h"
#include <malloc.h>
#include <math.h>
#include "InitCity.h"
#include "CityCoordinate.h"
#include <stdio.h>
#include <stdlib.h>

City **createPathOfCityVisit(int numOfCities){
  City **cities = malloc(sizeof(City**) * numOfCities);
  City *city = *cities;
  return cities;
}

// Cartesian formula
float findDistance(City *first, City *second){
  float  x,y, powX, powY;
  float ans, rounded;
  // x    = second.x_axis - first.x_axis;
  // y    = second.y_axis - first.y_axis;
  x    = (*second).x_axis - (*first).x_axis;
  y    = (*second).y_axis - (*first).y_axis;
  powX = x*x;
  powY = y*y;
  ans  = sqrt(powX + powY);

  return ((int)(ans * 1000 + .5) / 1000.0); // correct number to 3 significant
}





Path *TotalDistanceCities(City **cities, int arraySize){
  int i;
  float distance, TotalDistance = 0;

  for(i=0; i<arraySize; i++){
    distance = findDistance( &(*cities[i]), &(*cities[i+1]));
    TotalDistance = TotalDistance + distance;
    printf("%f\n", distance);
  }
  
  printf("%f\n", TotalDistance); 
  
}