#include "InitCity.h"

void setCity(City *target, float x_line, float y_line, int ID){
  target->x_axis = x_line;
  target->y_axis = y_line;
  target->ID = ID;
}

void setPath(Path *target, float distance, City **cities, int size){
  target->distance = distance;
  target->cities = cities;
  target->size = size;
}