#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"
#include <stdlib.h>

City city1,city2,city3,city4,city5,city6,city7,city8,city9,city10;

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
  setCity(&city1, 1, 1);
  setCity(&city2, 5, 7);
  setCity(&city3, 10, 9);
  setCity(&city4, 7, 3);
  setCity(&city5, 8, 5);
  setCity(&city6, 3, 6);
  setCity(&city7, 2, 10);
  setCity(&city8, 4, 8);
  setCity(&city9, 9, 2);
  setCity(&city10,10,4);
}

void tearDown(void)
{
}

void test_city_coordinate_should_set_correctly_acoordingly_the_given_value(void){
  TEST_ASSERT_EQUAL(city1.x_axis, 1);
  TEST_ASSERT_EQUAL(city1.y_axis, 1);
  TEST_ASSERT_EQUAL(city6.x_axis, 3);
  TEST_ASSERT_EQUAL(city6.y_axis, 6);
  TEST_ASSERT_EQUAL(city9.x_axis, 9);
  TEST_ASSERT_EQUAL(city9.y_axis, 2);
}

/**
* city1(1,1)    city(5,7)
* x = 5-1 = 4
* y = 7-1 = 6
* distance = square root ( 4^2 + 6^2 )
* distance  = 7.21
*/
void test_fitnessScore_to_find_the_distance_of_2_city(void){
  double ans = findDistance(&city1, &city2);
  TEST_ASSERT_EQUAL( ans, 7.21);
}
 //printf("random :%d\n", rand());
// Travel distance start sequence from city1 till city10;

