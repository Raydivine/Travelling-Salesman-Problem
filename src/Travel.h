#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
Path getDistanceFromPath( Path path);
Path MutationOfCities(Path path, City targetA, City targetB);
void genericBubbleSort ( Path table[], int size);

#endif // Travel_H
