#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"
#include <stdlib.h>
#include "LinkedList.h"

City cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ;

/**
*  y
*  ^
*10|   G(2,10)
*  |
*  |
* 9|                                      C(10,9)
*  |
* 8|           H(4,8)
*  |
* 7|                B(5,7)
*  |
* 6|         F(3,6)
*  |
* 5|                            E(8,5)
*  |
* 4|                                      J(10,4)
*  |
* 3|                         D(7,3)
*  |
* 2|                                 I(9,2)
*  |
* 1| A(1,1)
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

/**               2.2               1.4               2.8                 8.1
*      CityF(3,6)------> CityB(5,7)------> CityH(4,8)------> CityG(2,10)------> CityC(10,9)
*         ^                                                                       |
*         |                                                                       v
*         -------------------------------------------------------------------------
*                                           7.6
*   Total Distance = 22.1
*/
void test_TotalDistanceCities_given_travel_FBHGCF_should_return_total_distance(void){
  Path path;
  City *head =  cityListNew(&cityF);// assign cityF as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityH);
  addCityList(&head, &cityG);
  addCityList(&head, &cityC);
  cityC.next = head;// the last city go back to head
  City expectedCties[] = { cityF, cityB, cityH, cityG, cityC, cityB};
  path.cities = head;

  path = getDistanceFromPath(path);
  TEST_ASSERT_EQUAL( path.distance, 22.156);
  TEST_ASSERT_EQUAL( path.size    , 5);
  TEST_ASSERT_EQUAL( path.cities->ID                                    , cityF.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                              , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                        , cityH.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                  , cityG.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID            , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID      , cityF.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->ID, cityB.ID);
  clearCityList(head);
  clearCityList(path.cities);
}

/**
*-----------------------------------------------------------------------------------
* 1.Original Path                                                                   *
*                   cityA--->cityB-->cityC--->cityD                                 *
*                     ^                          |                                  *
*                     |                          v                                  *
*                  cityH<---cityG<---cityF<---cityE                                 *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 2. select cityB and cityF as target , reverse the link between them               *                                                                              *
*                                                                                   *
*                                                                                   *
*                               --------------------                                *
*                               ^                  |                                *
*                               |                  v                                *
*                   cityA--->(cityB)      NULL<---cityC<---cityD                    *
*                     ^                                   ^                         *
*                     |                                  |                          *
*                  cityH<---cityG            (cityF)----->cityE                     *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 3.Mutation                                                                        *
*                                                                                   *
*                   cityA--->cityB    cityC<---cityD                                *
*                     ^          \    /           |                                 *
*                     |           \ /             |                                 *
*                     |           / \             |                                 *
*                     |          v   v            v                                 *
*                  cityH<---cityG    cityF--->cityE                                 *
*-----------------------------------------------------------------------------------*
*/
void test_MutationOfCities_given_cityB_and_cityH_as_target_should_do_mutation_of_the_link(void){
  Path path;
  City *head =  cityListNew(&cityA);  // assign cityA as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  cityH.next = head;
  path.cities = head;

  path = MutationOfCities(path, &cityB, &cityF);
  TEST_ASSERT_EQUAL( path.size , 8);
  TEST_ASSERT_EQUAL( path.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                    , cityF.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                              , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                        , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                  , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
  clearCityList(head);
  clearCityList(path.cities);
}

/**
*                     $                 $
*                   cityA--->cityB-->cityC--->cityD                                 
*                     ^                          |                                  
*                     |                          v                                  
*                  cityH<---cityG<---cityF<---cityE 
*
*
*   AB+CD   <   AC+BD   
*/
void test_checkingFor2opt_given_cityA_cityG_should_no_do_2opt_because_they_cant_produce_better_chromesome(void){
  Path path;
  City *head =  NULL;  // assign cityA as head
  addCityList(&head, &cityA);
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  cityH.next = head;
  path.cities = head;

  int ans = checkingFor2opt(&cityA, &cityC);
//  TEST_ASSERT_EQUAL(ans , 0);
}

/**
* path1->distance = 22.156, path2->distance = 15.156
*
*                 sort
*  path1-path2  -------> path2-path1
*/
void test_bubbleSortForPath_given_array_of_2_path_should_sort_according_distance(void){
  Path path1, path2, pathArray[10];
  path1.distance = 22.156;
  path2.distance = 15.156;
  pathArray[0] = path1;
  pathArray[1] = path2;

  bubbleSortForPath( pathArray,2);
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
void test_bubbleSortForPath_given_array_of_5_path_should_sort_according_distance(void){
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

  bubbleSortForPath( pathArray,5);
  TEST_ASSERT_EQUAL( pathArray[0].distance, path1.distance);
  TEST_ASSERT_EQUAL( pathArray[1].distance, path2.distance);
  TEST_ASSERT_EQUAL( pathArray[2].distance, path5.distance);
  TEST_ASSERT_EQUAL( pathArray[3].distance, path3.distance);
  TEST_ASSERT_EQUAL( pathArray[4].distance, path4.distance);
}







