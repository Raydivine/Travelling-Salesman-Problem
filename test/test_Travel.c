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
  setCity(&cityA,  1,  1, 100);
  setCity(&cityB,  5,  7, 101);
  setCity(&cityC, 10,  9, 102);
  setCity(&cityD,  7,  3, 103);
  setCity(&cityE,  8,  5, 104);
  setCity(&cityF,  3,  6, 105);
  setCity(&cityG,  2, 10, 106);
  setCity(&cityH,  4,  8, 107);
  setCity(&cityI,  9,  2, 108);
  setCity(&cityJ, 10,  4, 109);
}

void tearDown(void)
{
}

void test_city_coordinate_should_set_correctly_acoordingly_the_given_value(void){
  TEST_ASSERT_EQUAL(cityA.x_axis, 1);
  TEST_ASSERT_EQUAL(cityA.y_axis, 1);
  TEST_ASSERT_EQUAL(cityA.ID  , 100);
  TEST_ASSERT_EQUAL(cityF.x_axis, 3);
  TEST_ASSERT_EQUAL(cityF.y_axis, 6);
  TEST_ASSERT_EQUAL(cityF.ID  , 105);
  TEST_ASSERT_EQUAL(cityI.x_axis, 9);
  TEST_ASSERT_EQUAL(cityI.y_axis, 2);
  TEST_ASSERT_EQUAL(cityI.ID  , 108);
}

void test_bubbleSort_shold_sort_the_number_from_small_to_big(void){
  float arr[]={2.23 ,6.56 ,1.11 ,9.55 ,3.22 ,5.77 ,7.65 ,6.21 ,8.63, 0, 4.11};
    printf("%f\n", arr[0]);
  bubbleSort(arr, 10);
  printf("%f\n", arr[0]);
  TEST_ASSERT_EQUAL( arr[0] , 1.11);


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

/**               2.2               1.4               2.8                 8.1               7.6
*      CityF(3,6)------> CityB(5,7)------> CityH(4,8)------> CityG(2,10)------> CityC(10,9)------> CityF(3,6)
*   Total Distance = 22.1
*/
void test_TotalDistanceCities_given_travel_FBHGCF_should_return_total_distance(void){
  Path path;
  City **cities = createPathOfCityVisit(5);
  cities[0] = &cityF;
  cities[1] = &cityB;
  cities[2] = &cityH;
  cities[3] = &cityG;
  cities[4] = &cityC;
  cities[5] = &cityF;
  City *city = *(cities);

  path = formPathFromCities(cities, 5);
  TEST_ASSERT_EQUAL(path.distance , 22.156);
  TEST_ASSERT_EQUAL(path.size  , 5);
  TEST_ASSERT_EQUAL(path.cities  , cities);
}

/**
*   path      CityF(3,6)------> CityB(5,7)------> CityH(4,8)------> CityG(2,10)------> CityC(10,9)------> CityF(3,6)
*                                                         to
*   newPath   CityB(5,7)------> CityG(2,10)------> CityC(10,9)------> CityH(4,8)------> CityF(3,6)------> CityB(5,7)
*/
void test_formNewPath_should_form_a_newPath_by_input_a_example_path(void){
  City **cities = createPathOfCityVisit(5);
  cities[0] = &cityF;
  cities[1] = &cityB;
  cities[2] = &cityH;
  cities[3] = &cityG;
  cities[4] = &cityC;
  cities[5] = &cityF;

  printf("start\n");
  Path path = setPath(path,22.156,cities,5);
  formNewPath(path);

}















