#ifndef CityCoordinate_H
#define CityCoordinate_H
#include <malloc.h>

typedef struct City City;
typedef struct Path Path;


struct City{
  float x_axis;
  float y_axis;
  int ID;
};

struct Path{
  float distance;
  City **cities;
  int size;
};

#endif // CityCoordinate_H
