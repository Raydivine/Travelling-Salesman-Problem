#ifndef Travel_H
#define Travel_H
#include "CityCoordinate.h"

float findDistance( City *first, City *second);
int checkIsCityNotUsed( City arr[], City target, int range);
int checkingFor2opt (City *cities, City targetA, City targetB);
void addCityToFront (City arr[], City target, int range);
void addCityToBack  (City arr[], City target, int range, int endID);
void addCityOfNeighbour (City arr[], City lastCityInArr, City *cities, int stop, int range);
void bubbleSortForNeighBour( NeighBour route[], int size);
void bubbleSortForPath( Path path[], int size);
City getFrontCity(City *cities, City target);
City getBackCity (City *cities, City target);
City copyCity    ( City city);
City *getRandomCity ( City *cities, City random);
Path copyPath (Path path, City arr[]);
Path getDistanceFromPath( Path path);
Path convertArrayToPath( City arr[], int range);
Path MutationCities(Path path, City targetA, City targetB);
Path initializePopulation (Path population, City tour[], City arr[], int size);
Path initPopulationTable(City arr[], int sizeOfPopulation, int size);
Path crossoverCities (Path path1, Path path2, City target, City arr[]);
Path travelInShortestPath( City arr[], int size);





#endif // Travel_H