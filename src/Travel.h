#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
Path getDistanceFromPath( Path path);
Path MutationOfCities(Path path, City *targetA, City *targetB);
Path crossoverCities(City *cities1st, City *cities2nd, City target);
Path copyCities (Path path);
City getFrontParent(City *cities, City target);
City getBackParent (City *cities, City target);
int  checkingFor2opt(City *targetA, City *targetB);
void bubbleSortForPath ( Path table[], int size);
City copyCity(City A, City B);


City getParentCities(City *cities, City target);
City getChildCities(City *cities, City target);
#endif // Travel_H
