#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
Path getDistanceFromPath( Path path);
Path MutationCities(Path path, City *targetA, City *targetB);
Path crossoverCities (Path path1, Path path2, City target);

Path copyPath (Path path);
City copyCity ( City city);
City getFrontParent(City *cities, City target);
City getBackParent (City *cities, City target);
void destinationDistanceArray(City center, City neighBours[], City allCities[], int size);
void addCityToFront (City arr[], City target, int range);
void addCityToBack  (City arr[], City target, int range, int endID);
void addCityOfNeighBour (City arr[], City lastCityInArr, City *cities, int stop, int range);
Path convertArrayToPath( City arr[], int range);
int checkIsCityNotUsed( City arr[], City target, int range);
int checkingFor2opt(City *targetA, City *targetB);


int checkIsTargetNotInCities( City *cities, City target);
void bubbleSortForPath ( Path table[], int size);
void bubbleSortForNeighBour( NeighBour route[], int size);

#endif // Travel_H