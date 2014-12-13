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
};

struct NeighBour{
  City neighBour;
  float distance;
};

struct Path{
  float distance;
  City *cities;
  int size;
};

#endif // CityCoordinate_H