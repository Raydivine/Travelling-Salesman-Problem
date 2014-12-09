#ifndef CityCoordinate_H
#define CityCoordinate_H
#include <malloc.h>

typedef struct City City;
typedef struct Path Path;
typedef struct NeighBour NeighBour;

struct City{
  float x_axis;
  float y_axis;
  int ID;
  City *next;
  City *neighBours;
};

struct NeighBour{
  City center;
  City object;
  float distance;
};

struct Path{
  float distance;
  City *cities;
  int size;
};



#endif // CityCoordinate_H


/**
*  y
*  ^
*  |
*10|   G(2,10)
*  |
*  |
* 9|                                      C(10,9)
*  |
* 8|           H(4,8)
*  |
* 7|                B(5,7)
*  |
* 6|         F(3,6)
*  |
* 5|                            E(8,5)
*  |
* 4|                                      J(10,4)
*  |
* 3|                         D(7,3)
*  |
* 2|                                 I(9,2)
*  |
* 1| A(1,1)
*  |__________________________________________> x
* 0   1   2   3   4   5   6   7   8   9   10
*
*/