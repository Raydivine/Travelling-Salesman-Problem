#include "Travel.h"
#include <stdio.h>
#include <math.h>
#include "CityCoordinate.h"
#include <stdlib.h>

// Cartesian formula 
double findDistance (City *first, City *second){
  int     x,y, powX, powY;
  double ans, rounded;
  x    = (*second).x_axis - (*first).x_axis;
  y    = (*second).y_axis - (*first).y_axis;
  powX = x*x;
  powY = y*y;
  ans  = sqrt(powX + powY);

  return ((int)(ans * 100 + .5) / 100.0);
}

