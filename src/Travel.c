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

  float link1 = fitnessScore(A,B);
  float link2 = fitnessScore(B,C);
  float link3 = fitnessScore(C,D);
  float link4 = fitnessScore(D,E);
  float link5 = fitnessScore(E,F);
  float link6 = fitnessScore(F,G);
  float link7 = fitnessScore(G,H);
  float link8 = fitnessScore(H,I);
  float link9 = fitnessScore(I,J); 
  float TotalDistance = link1 + link2 + link3 + link4 + link5 + link6 + link7 + link8 + link9; 
  return TotalDistance; 
  printf("%f\n", TotalDistance);
}