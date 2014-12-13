#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
int checkIsCityNotUsed( City arr[], City target, int range);
int checkingFor2opt(City *targetA, City *targetB);
void addCityToFront (City arr[], City target, int range);
void addCityToBack  (City arr[], City target, int range, int endID);
void addCityOfNeighbour (City arr[], City lastCityInArr, City *cities, int stop, int range);
void bubbleSortForPath ( Path table[], int size);
void bubbleSortForNeighBour( NeighBour route[], int size);
City *getRandomCity ( City *cities, City random);
City getFrontCity(City *cities, City target);
City getBackCity (City *cities, City target);
City copyCity ( City city);
Path copyPath (Path path, City arr[]);
Path getDistanceFromPath( Path path);
Path convertArrayToPath( City arr[], int range);
Path MutationCities(Path path, City *targetA, City *targetB);

Path changeTheLinkedListElementToArrayElement( Path path , City arr[], int size);
Path crossoverCities (Path path1, Path path2, City target, City arr[]);
Path MutationCitiesWithRandomInput(Path path, City targetA, City targetB);
int checkingFor2optWithRandomInput(Path path, City targetA, City targetB);
Path travelInShortestPath( City *cities1, City *cities2, City arr[]);




#endif // Travel_H