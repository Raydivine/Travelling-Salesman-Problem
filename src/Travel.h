#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
Path getDistanceFromPath( Path path);
Path MutationOfCities(Path path, City *targetA, City *targetB);
Path corssoverCities(City *cities1st, City *cities2nd);
int  checkingFor2opt(City *targetA, City *targetB);
void bubbleSortForPath ( Path table[], int size);

#endif // Travel_H
