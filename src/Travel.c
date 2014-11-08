#include "Travel.h"
#include <stdio.h>
#include <math.h>
#include "CityCoordinate.h"
#include <stdlib.h>


float fitnessScore(City A, City B){
  int x,y, powX, powY;
  float ans, rounded;

  x = B.x_axis - A.x_axis;
  y = B.y_axis - A.y_axis;

  powX = x*x;
  powY = y*y;
  ans = sqrt(powX + powY);
  rounded = ((int)(ans * 100 + .5) / 100.0);
  return rounded;
  // printf("%d\n",powX + powY);
  // printf("%f\n",ans);
  // printf("%f\n",rounded);
}

float distanceForTravel(City A, City B ,City C, City D, City E,
                        City F, City G, City H, City I, City J)
{
  float TotalDistance;
  TotalDistance = fitnessScore(A,B) + fitnessScore(B,C) + fitnessScore(C,D) +
                  fitnessScore(D,E) + fitnessScore(E,F) + fitnessScore(F,G) +
                  fitnessScore(G,H) + fitnessScore(H,I) + fitnessScore(I,J) ;
  return ((int)(TotalDistance * 100 + .5) / 100.0);
  printf("%f\n", TotalDistance);
}