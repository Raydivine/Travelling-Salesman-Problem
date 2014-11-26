#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"
#include <stdlib.h>

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
  setCity(&cityA,  1,  1, 100, NULL);
  setCity(&cityB,  5,  7, 101, NULL);
  setCity(&cityC, 10,  9, 102, NULL);
  setCity(&cityD,  7,  3, 103, NULL);
  setCity(&cityE,  8,  5, 104, NULL);
  setCity(&cityF,  3,  6, 105, NULL);
  setCity(&cityG,  2, 10, 106, NULL);
  setCity(&cityH,  4,  8, 107, NULL);
  setCity(&cityI,  9,  2, 108, NULL);
  setCity(&cityJ, 10,  4, 109, NULL);
}

void tearDown(void)
{
}

void test_city_coordinate_should_set_correctly_acoordingly_the_given_value(void){
  TEST_ASSERT_EQUAL(cityA.x_axis, 1);
  TEST_ASSERT_EQUAL(cityA.y_axis, 1);
  TEST_ASSERT_EQUAL(cityF.x_axis, 3);
  TEST_ASSERT_EQUAL(cityF.y_axis, 6);
  TEST_ASSERT_EQUAL(cityI.x_axis, 9);
  TEST_ASSERT_EQUAL(cityI.y_axis, 2);
  TEST_ASSERT_EQUAL(cityA.ID, 100);
  TEST_ASSERT_EQUAL(cityF.ID, 105);
  TEST_ASSERT_EQUAL(cityI.ID, 108);
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
*      CityF(3,6)------> CityB(5,7)------> CityH(4,8)------> CityG(2,10)------> CityC(10,9)------>null    CityF(3,6)
*   Total Distance = 22.1
*/
void test_TotalDistanceCities_given_travel_FBHGCF_should_return_total_distance(void){
  Path path;
  printf("%p\n",  cityF.next);
  cityF.next = &cityB;
  cityB.next = &cityH;
  cityH.next = &cityG;
  cityG.next = &cityC;
  cityC.next = &cityF;
  cityF.next = NULL;
  path.cities = cityF;
  printf("%p\n", cityF);
  printf("%p\n", cityB);
  printf("%p\n", cityH);
  printf("%p\n",  cityF.next);

 // getDistanceFromPath(path);
 // TEST_ASSERT_EQUAL( path.distance, 22.1);
}

/**
* path1->distance = 22.156, path2->distance = 15.156
*
*                 sort
*  path1-path2  -------> path2-path1
*/
void test_genericBubbleSort_given_array_of_2_path_should_sort_according_distance(void){
  Path path1, path2, pathArray[10];
  path1.distance = 22.156;
  path2.distance = 15.156;
  pathArray[0] = path1;
  pathArray[1] = path2;

  genericBubbleSort( pathArray,2);
  TEST_ASSERT_EQUAL( pathArray[0].distance, path2.distance);
  TEST_ASSERT_EQUAL( pathArray[1].distance, path1.distance);
}

/**
*
*
*  path1 ---> path2 ---> path3 ---> path4 ---> path5
*                     |sort
*                     v
*  path2 ---> path1 ---> path5 ---> path3 ---> path4
*/
void test_genericBubbleSort_given_array_of_5_path_should_sort_according_distance(void){
  Path path1, path2, path3, path4, path5, pathArray[10];
  path1.distance = 22.156;
  path2.distance = 45.156;
  path3.distance = 75.156;
  path4.distance = 95.156;
  path5.distance = 55.156;
  pathArray[0] = path1;
  pathArray[1] = path2;
  pathArray[2] = path3;
  pathArray[3] = path4;
  pathArray[4] = path5;

  genericBubbleSort( pathArray,5);
  TEST_ASSERT_EQUAL( pathArray[0].distance, path1.distance);
  TEST_ASSERT_EQUAL( pathArray[1].distance, path2.distance);
  TEST_ASSERT_EQUAL( pathArray[2].distance, path5.distance);
  TEST_ASSERT_EQUAL( pathArray[3].distance, path3.distance);
  TEST_ASSERT_EQUAL( pathArray[4].distance, path4.distance);
}

/**
*   path      CityF(3,6)------> CityB(5,7)------> CityH(4,8)------> CityG(2,10)------> CityC(10,9)------> CityF(3,6)
*                                                         to
*   newPath   CityB(5,7)------> CityG(2,10)------> CityC(10,9)------> CityH(4,8)------> CityF(3,6)------> CityB(5,7)
*/
void xtest_formNewPath_should_form_a_newPath_by_input_a_example_path(void){

}









