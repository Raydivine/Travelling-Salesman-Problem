#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"

City city1,city2,city3,city4,city5,city6,city7,city8,city9,city10;

void setUp(void){
  setCity(&city1, 1, 1);
  setCity(&city2, 5, 7);
  setCity(&city3, 2, 9);
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

void test_city_Initilization_should_set_correctly_acoording_the_given_value(){

  TEST_ASSERT_EQUAL( city1.x_axis, 1);
  TEST_ASSERT_EQUAL( city1.y_axis, 1);
  TEST_ASSERT_EQUAL( city6.x_axis, 3);
  TEST_ASSERT_EQUAL( city6.y_axis, 6);
  TEST_ASSERT_EQUAL( city9.x_axis, 9);
  TEST_ASSERT_EQUAL( city9.y_axis, 2);

}