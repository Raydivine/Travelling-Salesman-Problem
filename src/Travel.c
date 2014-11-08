#include "Travel.h"
#include <stdio.h>
#include <math.h>
#include "CityCoordinate.h"
#include <stdlib.h>


float fitnessScore(City city1, City city2){
  int x,y, powX, powY;
  float ans, rounded;

  x = city2.x_axis - city1.x_axis;
  y = city2.y_axis - city1.y_axis;

  powX = x*x;
  powY = y*y;
  ans = sqrt(powX + powY);
  rounded = ((int)(ans * 100 + .5) / 100.0);
  printf("%d\n",powX + powY);
  printf("%f\n",ans);
  printf("%f\n",rounded);
  return rounded;

}