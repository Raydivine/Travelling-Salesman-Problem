#include "InitCity.h"
#include "CityCoordinate.h"

void setCity(City *target, float x_line, float y_line, int ID, City *next){
  target->x_axis = x_line;
  target->y_axis = y_line;
  target->ID = ID;
  target->next = next;
}

void setPath(Path target, float distance, City *cities, int size){
  target.distance = distance;
  target.cities = cities;
  target.size = size;
}

void setLocate(Locate locate, int ID, City city[], int size){
  int i;
  
  locate.ID = ID;
  
}