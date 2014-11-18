#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"
#include <stdlib.h>

#define SIZE 1000000


City cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ;

/**
*  y
*  ^
*10|   (2,10)
*  |
*  |
* 9|                                      (10,9)
*  |
* 8|           (4,8)
*  |
* 7|                (5,7)
*  |
* 6|         (3,6)
*  |
* 5|                            (8,5)
*  |
* 4|                                      (10,4)
*  |
* 3|                         (7,3)
*  |
* 2|                                 (9,2)
*  |
* 1| (1,1)
*  |__________________________________________> x
* 0   1   2   3   4   5   6   7   8   9   10
*
*/

void setUp(void){
  setCity(&cityA,  1,  1, 'A');
  setCity(&cityB,  5,  7, 'B');
  setCity(&cityC, 10,  9, 'C');
  setCity(&cityD,  7,  3, 'D');
  setCity(&cityE,  8,  5, 'E');
  setCity(&cityF,  3,  6, 'F');
  setCity(&cityG,  2, 10, 'G');
  setCity(&cityH,  4,  8, 'H');
  setCity(&cityI,  9,  2, 'I');
  setCity(&cityJ, 10,  4, 'J');
}

void tearDown(void)
{
}

void test_city_coordinate_should_set_correctly_acoordingly_the_given_value(void){
  TEST_ASSERT_EQUAL(cityA.x_axis, 1);
  TEST_ASSERT_EQUAL(cityA.y_axis, 1);
  TEST_ASSERT_EQUAL(cityA.cityID,'A');
  TEST_ASSERT_EQUAL(cityF.x_axis, 3);
  TEST_ASSERT_EQUAL(cityF.y_axis, 6);
  TEST_ASSERT_EQUAL(cityF.cityID,'F');
  TEST_ASSERT_EQUAL(cityI.x_axis, 9);
  TEST_ASSERT_EQUAL(cityI.y_axis, 2);
  TEST_ASSERT_EQUAL(cityI.cityID,'I');
}

/**
* city1(1,1)    city(5,7)
* x = 5-1 = 4
* y = 7-1 = 6
* distance = square root ( 4^2 + 6^2 )
* distance  = 7.211
*/
void test_fitnessScore_to_find_the_distance_of_2_city(void){
  float ans = findDistance(&cityA, &cityB);
  TEST_ASSERT_EQUAL( ans, 7.211);
}

void test_createPathOfCityVisit_should_init_cities_as_array_size_10(void){
  int size;
  City *city;
  city = createPathOfCityVisit(10);
 // size = 
}



/**
*      CityF(3,6)------> CityB(5,7)------> CityH(4,8)------> CityG(2,10)------> CityC(10,9)------> CityF(3,6)
*
*/
void TEST_TotalDistanceCities_given_travel_FBHGCF_should_return_total_distance(void){
  City arrayCity[] = {cityF, cityB, cityH, cityG, cityC};
  TotalDistanceCities(arrayCity);
}
















