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
void initPopulationTable( Path population[], City arr[], int sizeOfPopulation, int size);
void freePopulationTable(Path population[], int sizeOfPopulation);
void printfOutPopulatointable(Path population[], int sizeOfPopulation);
void printOutCitiesID( City *cities);
void copyArray( City clone[], City arr[], int size);
void clearCityArray(City arr[], int size);
void shuffleArray( City randArr[], int size);
void locateNeighBoursBasedOnGivenNumber( City shortDistanceArr[], City arr[], City cityLookingForNeighBour, int numOfShortDistanceCity, int size);
City getFrontCity(City *cities, City target);
City getBackCity (City *cities, City target);
City copyCity    ( City city);
Path copyPath (Path path, City arr[]);
Path getDistanceFromPath( Path path);
Path convertArrayToPath( City arr[], int range);
Path MutationCities(Path path, City targetA, City targetB);
Path crossoverCities (Path path1, Path path2, City target, City arr[]);
Path InitPathFromTheGivenArrayByUsingLocalElement( City sampleArr[], City localArr[], int size);
Path doMutation ( Path path, City arr[], int size);
Path doCrossover( Path path1, Path path2, City arr[], City crossArr[], int size);
Path solveTSP( City arr[], int sizeOfPopulation, int sizeOfCity, int maxNumGeneration);

Path mock_doMutation( Path path, City arr[], int size);
Path mock_doCrossover( Path path1, Path path2, City arr[], City crossArr[], int size);

#endif // Travel_H