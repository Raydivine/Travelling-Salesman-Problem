#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
Path getDistanceFromPath( Path path);
Path MutationOfCities(Path path, City *targetA, City *targetB);
Path crossoverCities (Path path1, Path path2, City target);
Path copyCities (Path path);
City getFrontParent(City *cities, City target);
City getBackParent (City *cities, City target);
City removeSameElementInCities(City *mid, int size);
int checkingFor2opt(City *targetA, City *targetB);
int checkIsTargetNotInCities( City *cities, City target);
void bubbleSortForPath ( Path table[], int size);
City copyCity(City A, City B);


#endif // Travel_H
