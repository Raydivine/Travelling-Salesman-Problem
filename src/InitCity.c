#include "InitCity.h"

void setCity(City *target, float x_line, float y_line, char ID){
  target->x_axis = x_line;
  target->y_axis = y_line;
  target->cityID = ID;
}