#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"


float findDistance( City *first, City *second);
Path getDistanceFromPath( Path path);
Path MutationOfCities(Path path, City *targetA, City *targetB);
Path crossoverCities (Path path1, Path path2, City target);
Path copyCities (Path path);
City copyCity(City A, City B);
City getFrontParent(City *cities, City target);
City getBackParent (City *cities, City target);
void destinationDistanceArray(City center, City neighBours[], City allCities[], int size);
void addCityToFront (City arr[], City target, int range);
void addCityToBack  (City arr[], City target, int range, int endID);
void bestCities (City bestCities[], City target, City refference[]);
void addRestOfCities (City arr[], City *cities, int stop, int end, int range);
void convertArrayToLinkedlist(City *cities , City arr[], int range);
int checkIsCityNotUsed( City arr[], City target, int range);
int checkingFor2opt(City *targetA, City *targetB);


City removeSameElementInCities(City *mid, int size);
int checkIsTargetNotInCities( City *cities, City target);
void bubbleSortForPath ( Path table[], int size);
void bubbleSortForNeighBour( NeighBour route[], int size);

#endif // Travel_H
