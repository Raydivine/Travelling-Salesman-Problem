#ifndef InitCity_H
#define InitCity_H
#include "CityCoordinate.h"

void setCity(City *target, float x_line  , float y_line , int ID  );
void setPath(Path target, float distance, City cities, int size);

#endif // InitCity_H
