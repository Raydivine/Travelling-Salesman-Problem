#ifndef CityCoordinate_H
#define CityCoordinate_H
#include <malloc.h>

typedef struct City City;
typedef struct Path Path;


struct City{
  float x_axis;
  float y_axis;
  char cityID;
};

struct Path{
  float distance;
};

#endif // CityCoordinate_H
