#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"
#include <stdlib.h>
#include "LinkedList.h"

City cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ,
     cityK,cityL,cityM,cityN,cityO,cityP,cityQ,cityR,cityS,cityT;
/**
*  y
*  ^
*20|                                                                                  K(19,20)
*  |
*19|                                       Q(11,19)
*  |
*18|                                                       T(14,18)
*  |
*17|                                                              O(16,17)
*  |
*16|                                             R(12,16)
*  |
*15|                                                                M(15,15)
*  |
*14|                                                  N(13,14)
*  |
*13|                                                                                     P(20,13)
*  |
*12|                                                                          S(17,12)
*  |
*11|                                                                         L(18,11)
*  |
*10|   G(2,10)
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
*  |____________________________________________________________________________________________> x
* 0   1   2   3   4   5   6   7   8   9   10  11   12   13   14   15   16   17   18   19   20
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
  setCity(&cityK, 19, 20, 110, NULL);
  setCity(&cityL, 18, 11, 111, NULL);
  setCity(&cityM, 15, 15, 112, NULL);
  setCity(&cityN, 13, 14, 113, NULL);
  setCity(&cityO, 16, 17, 114, NULL);
  setCity(&cityP, 20, 13, 115, NULL);
  setCity(&cityQ, 11, 19, 116, NULL);
  setCity(&cityR, 12, 16, 117, NULL);
  setCity(&cityS, 17, 12, 118, NULL);
  setCity(&cityT, 14, 18, 119, NULL);
}

void tearDown(void){}

/**
* city1(1,1)    city(5,7)
* x = 5-1 = 4
* y = 7-1 = 6
* distance = square root ( 4^2 + 6^2 )
* distance  = 7.211
*/
void xtest_fitnessScore_to_find_the_distance_of_2_city(void){
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
void xtest_TotalDistanceCities_given_travel_FBHGCF_should_return_total_distance(void){
  Path path;
  City *head =  cityListNew(&cityF);// assign cityF as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityH);
  addCityList(&head, &cityG);
  addCityList(&head, &cityC);
  addCityList(&head, &cityF);
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
*
*   Original:   CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH
*                                                     |  copy
*   Clone   :   CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH
*
*/
void test_copyPath_should_copy_a_new_cities_list(void){
  City *head =  cityListNew(&cityA);
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  Path path;
  path.cities = head;
  path.size = 8;

  Path clonePath = copyPath(path); 
  TEST_ASSERT_EQUAL( clonePath.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->ID                                    , cityC.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->ID                  , cityF.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
  clearCityList(head);
  clearCityList(path.cities);
}

/**
* path1->distance = 22.156, path2->distance = 15.156
*
*                 sort
*  path1-path2  -------> path2-path1
*/
void xtest_bubbleSortForPath_given_array_of_2_path_should_sort_according_distance(void){
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
void xtest_bubbleSortForPath_given_array_of_5_path_should_sort_according_distance(void){
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

/**
*-----------------------------------------------------------------------------------
* 1.Original Path      $                                                            *
*                   cityA--->cityB-->cityC--->cityD                                 *
*                     ^                          |                                  *
*                     |                $          v                                 *
*                  cityH<---cityG<---cityF<---cityE                                 *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 2. select cityB and cityF as target , reverse the link between them               *
*                                                                                   *
*                                                                                   *
*                                         NULL                                      *
*                                          ^                                        *
*                                         |                                         *
*                   cityA--->(cityB)--->cityC<---cityD                              *
*                     ^                            ^                                *
*                     |                            |                                *
*                  cityH<---cityG   (cityF)----->cityE                              *
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
void xtest_MutationCities_given_cityB_and_cityH_as_target_should_do_mutation_of_the_link(void){
  Path path;
  City *head =  cityListNew(&cityA);  // assign cityA as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  path.cities = head;

  path = MutationCities(path, &cityB, &cityF);
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

/**----------------------------------------------------------------------------------
* 1.Original Path       $               $                                           *
*                   cityA--->cityB-->cityC--->cityD                                 *
*                     ^                          |                                  *
*                     |                          v                                  *
*                  cityH<---cityG<---cityF<---cityE                                 *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 2. select cityA and cityC as target , reverse the link between them               *                                                                              *
*                                                                                   *
*                                                                                   *
*                                                                                   *
*             -------------------------                                             *
*            |                        |                                             *
*            v                        v                                             *
*          cityA   NULL<---cityB<---cityC--->cityD                                  *
*             ^                                 |                                   *
*             |                                 v                                   *
*             ----cityH<---cityG<---cityF<---cityE                                  *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 3.Mutation  A point to B, A next point to B next                                  *
*                                                                                   *
*                   cityA--->cityC-->cityB--->cityD                                 *
*                     ^                          |                                  *
*                     |                          v                                  *
*                  cityH<---cityG<---cityF<---cityE                                 *
*-----------------------------------------------------------------------------------*/
void xtest_MutationCities_given_2_near_city_should_do_reverse(void){
  Path path;
  City *head =  cityListNew(&cityA);  // assign cityA as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  path.cities = head;

  path = MutationCities(path, &cityA, &cityC);
  TEST_ASSERT_EQUAL( path.size , 8);
  TEST_ASSERT_EQUAL( path.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                          , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                    , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                  , cityF.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
  clearCityList(head);
  clearCityList(path.cities);
}

/**---------------------------------------------------------------------------------*
* 1.Original Path                                                                   *
*                       $       $                                                   *
*                   cityA--->cityB-->cityC--->cityD                                 *
*                     ^                          |                                  *
*                     |                          v                                  *
*                  cityH<---cityG<---cityF<---cityE                                 *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 2. cityB reversed and point to NULL                                               *
*                                                                                   *
*          cityA   NULL<---cityB<---cityC--->cityD                                  *
*             ^                                 |                                   *
*             |                                 v                                   *
*             ----cityH<---cityG<---cityF<---cityE                                  *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 3. Then cityA point to cityB, so actually its come back original form             *
*                                                                                   *
*                   cityA--->cityB-->cityC--->cityD                                 *
*                     ^                          |                                  *
*                     |                          v                                  *
*                  cityH<---cityG<---cityF<---cityE                                 *
*-----------------------------------------------------------------------------------*/
void xtest_MutationCities_given_2_besides_city_should_do_nothing(void){
  Path path;
  City *head =  cityListNew(&cityA);
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  path.cities = head;

  path = MutationCities(path, &cityA, &cityB);
  TEST_ASSERT_EQUAL( path.size , 8);
  TEST_ASSERT_EQUAL( path.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                    , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                  , cityF.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
  clearCityList(head);
  clearCityList(path.cities);
}

/**
*                       $
*                   cityA--->cityB-->cityC--->cityD
*                     ^                          |
*                     |                          v
*                  cityH<---cityG<---cityF<---cityE
*/
void xtest_MutationCities_given_2_same_city_should_directly_return(void){
  Path path;
  City *head =  cityListNew(&cityA);
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  path.cities = head;

  path = MutationCities(path, &cityA, &cityA);
  TEST_ASSERT_EQUAL( path.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                    , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                  , cityF.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
  clearCityList(head);
  clearCityList(path.cities);
}

/**
*   A(1,1)  B(5,7)  C(10,9)   D(7,3)
*                     $                 $
*                   cityA--->cityB-->cityC--->cityD
*                     ^                          |
*                     |                          v
*                  cityH<---cityG<---cityF<---cityE
*
*                 AB + CD = 13.91,  AC + BD = 16.51
*
*                            AC+BD > AB+CD
*
*                   should not do 2opt because cannot get shorter distance
*/
void xtest_checkingFor2opt_given_cityA_cityG_should_no_do_2opt_because_they_cant_produce_better_chromesome(void){
  Path path;
  City *head =  cityListNew(&cityA);  // assign cityA as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  path.cities = head;

  int ans = checkingFor2opt(&cityA, &cityC);
  TEST_ASSERT_EQUAL(ans , 0);
  clearCityList(head);
}

/**
*   A(1,1)  B(5,7)  F(3,6)   G(2,10)
*                     $
*                   cityA--->cityB-->cityC--->cityD
*                     ^                          |
*                     |                  $       v
*                  cityH<---cityG<---cityF<---cityE
*
*                 AB + FG = 11.33,  AF + BG = 9.62
*
*                         AF+BG  <  AB + FG
*
*                should  do 2opt because  get shorter distance
*/
void xtest_checkingFor2opt_given_cityA_cityG_should_do_2opt_because_they_produce_better_chromesome(void){
  Path path;
  City *head =  cityListNew(&cityA);  // assign cityA as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  path.cities = head;

  int ans = checkingFor2opt(&cityA, &cityF);
  TEST_ASSERT_EQUAL(ans , 1);
  clearCityList(head);
}

void xtest_checkingFor2opt_given_same_city_to_do_2opt_should_return_0(void){
  Path path;
  City *head =  cityListNew(&cityA);  // assign cityA as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);
  addCityList(&head, &cityA);
  path.cities = head;

  int ans = checkingFor2opt(&cityA, &cityA);
  TEST_ASSERT_EQUAL(ans , 0);
  clearCityList(head);
}

void xtest_checkIsCityNotUsed_given_array_A_B_C_and_put_in_cityD_should_return_1_because_cityD_is_not_inside(void){
  City arr[] = { cityA, cityB, cityC };

  int ans = checkIsCityNotUsed( arr, cityD, 4);
  TEST_ASSERT_EQUAL( ans, 1);
}

void xtest_checkIsCityNotUsed_given_array_A_B_C_and_put_in_cityA_should_return_0_because_cityA_is_inside(void){
  City arr[] = { cityA, cityB, cityC };

  int ans = checkIsCityNotUsed( arr, cityA, 4);
  TEST_ASSERT_EQUAL( ans, 0);
}

void xtest_getFrontCity_given_linkedList_B_E_C_A_G_and_target_G_should_get_cityA(void){
  City *head =  cityListNew(&cityB);
  addCityList(&head, &cityE);
  addCityList(&head, &cityC);
  addCityList(&head, &cityA);
  addCityList(&head, &cityG);
  addCityList(&head, &cityB);

  City city = getFrontCity(head, cityG);
  TEST_ASSERT_EQUAL( city.ID, cityA.ID);
  clearCityList(head);
}

void xtest_getBackCity_given_linkedList_B_E_C_A_G_and_target_C_should_get_cityA(void){
  City *head =  cityListNew(&cityB);
  addCityList(&head, &cityE);
  addCityList(&head, &cityC);
  addCityList(&head, &cityA);
  addCityList(&head, &cityG);
  addCityList(&head, &cityB);

  City city = getBackCity(head, cityC);
  TEST_ASSERT_EQUAL( city.ID, cityA.ID);
  clearCityList(head);
}

void Xtest_convertArrayToPath_given_array_A_B_C_D_E_should_convert_to_path__A_B_C_D_E_(void){
  City arr[] = {cityA, cityB, cityC, cityD, cityE};

  Path path = convertArrayToPath( arr, 5);
  TEST_ASSERT_EQUAL( path.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                    , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                  , cityA.ID);
}

/**--------------------------------------------------------------------------------------------------------
* 1) The 2 chromosome cities shown below, and cityE is choose to do crossover                             *
*                                                                                                         *
*      ----------------left-------------------       $$$$$                                                *
*     CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH              *
*                                                                                                         *
*                                                                                                         *
*                              $$$$$       ----------------Right-------------------                       *
*      CityC------> CityD----->CityE----->CityH------>CityG----->CityB----->CityF------>CityA             *
*                                                                                                         *
*                                                                                                         *
*----------------------------------------------------------------------------------------------------------
* 2) Select cityE as mid, fill the city 1by1 from chromose1'left and chromose2'Right,                     *
*    if the coming city is is already exists, then stop and form a crossover link                         *
*                                                                                                         *
*                                                  mid                                                    *
*             CityB----->CityC------>CityD----->CityE----->CityH------>CityG                              *
*                                                                                                         *
*                                                                                                         *
*----------------------------------------------------------------------------------------------------------
*  3) add the rest of city to behind cityG, the added city's sequence is based of the distance to cityG   *
*                                                             $                                           *
*  CityB----->CityC------>CityD----->CityE----->CityH------>CityG------>CityF------->cityA                *
*                                                                       (near  to    far )                *
*                                                                                                         *
*---------------------------------------------------------------------------------------------------------*/
void xtest_corssoverCities_given_2_cities_and_choose_cityE_should_do_crossover_and_form_new_cities(void){
  City  cityA1 = cityA, cityB1 = cityB, cityC1 = cityC, cityD1 = cityD, cityE1 = cityE,
        cityF1 = cityF, cityG1 = cityG, cityH1 = cityH, cityI1 = cityI, cityJ1 = cityJ;

  City *head1 =  cityListNew(&cityA);
  addCityList(&head1, &cityB);
  addCityList(&head1, &cityC);
  addCityList(&head1, &cityD);
  addCityList(&head1, &cityE);
  addCityList(&head1, &cityF);
  addCityList(&head1, &cityG);
  addCityList(&head1, &cityH);
  addCityList(&head1, &cityA);

  City *head2 =  cityListNew(&cityC1);
  addCityList(&head2, &cityD1);
  addCityList(&head2, &cityE1);
  addCityList(&head2, &cityH1);
  addCityList(&head2, &cityG1);
  addCityList(&head2, &cityB1);
  addCityList(&head2, &cityF1);
  addCityList(&head2, &cityA1);
  addCityList(&head2, &cityC1);

  Path path1, path2, crossoverPath;
  path1.cities = head1;
  path1.size   = 8;
  path2.cities = head2;
  path2.size   = 8;

  crossoverPath = crossoverCities(path1, path2, cityE);
  TEST_ASSERT_EQUAL( crossoverPath.cities->ID                                                , cityB.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->ID                                          , cityC.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->ID                                    , cityD.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->ID                              , cityE.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->ID                        , cityH.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->ID                  , cityG.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->next->ID            , cityF.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->next->next->ID      , cityA.ID);
  clearCityList(head1);
  clearCityList(head2);
  clearCityList(crossoverPath.cities);
}

/**----------------------------------------------------------------------------------------------------------
* 1) The 2 chromosome cities shown below, and cityA is choose to do crossover                               *
*                                                                                                           *
*      $$$$$                                                                                                *
*     CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH                *
*                                                                                                           *                                                                                                       *
*                                                                                       $$$$$               *
*      CityC------> CityD----->CityE----->CityH------>CityG----->CityB----->CityF------>CityA               *
*                                                                                                           *                                                                                                          *
*------------------------------------------------------------------------------------------------------------
* 2) Select cityA as mid, fill the city 1by1 from chromose1'left and chromose2'Right,                       *
*    if the coming city is is already exists, then stop and form a crossover link                           *
*                                                                                                           *
*                                        mid                                                                *
*    CityF----->CityG------>CityH----->CityA------>CityC----->CityD------>CityE                             *
*                                                                                                           *                                                                                                          *
*------------------------------------------------------------------------------------------------------------
*  3) add the rest of city to behind                                                                        *
*                                                                                                           *
*  CityF----->CityG------>CityH----->CityA------>CityC----->CityD------>CityE----->CityB                    *
*                                                                                                           *
*                                                                                                           *
*-----------------------------------------------------------------------------------------------------------*/
void xtest_corssoverCities_given_2_cities_and_choose_cityA_should_do_crossover_and_form_new_cities(void){
  City  cityA1 = cityA, cityB1 = cityB, cityC1 = cityC, cityD1 = cityD, cityE1 = cityE,
        cityF1 = cityF, cityG1 = cityG, cityH1 = cityH, cityI1 = cityI, cityJ1 = cityJ;

  City *head1 =  cityListNew(&cityA);
  addCityList(&head1, &cityB);
  addCityList(&head1, &cityC);
  addCityList(&head1, &cityD);
  addCityList(&head1, &cityE);
  addCityList(&head1, &cityF);
  addCityList(&head1, &cityG);
  addCityList(&head1, &cityH);
  addCityList(&head1, &cityA);

  City *head2 =  cityListNew(&cityC1);
  addCityList(&head2, &cityD1);
  addCityList(&head2, &cityE1);
  addCityList(&head2, &cityH1);
  addCityList(&head2, &cityG1);
  addCityList(&head2, &cityB1);
  addCityList(&head2, &cityF1);
  addCityList(&head2, &cityA1);
  addCityList(&head2, &cityC1);

  Path path1, path2, crossoverPath;
  path1.cities = head1;
  path1.size   = 8;
  path2.cities = head2;
  path2.size   = 8;

  crossoverPath = crossoverCities(path1, path2, cityA);
  TEST_ASSERT_EQUAL( crossoverPath.cities->ID                                                , cityF.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->ID                                          , cityG.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->ID                                    , cityH.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->ID                              , cityA.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->ID                        , cityC.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->ID                  , cityD.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->next->ID            , cityE.ID);
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->next->next->ID      , cityB.ID);
  clearCityList(head1);
  clearCityList(head2);
  clearCityList(crossoverPath.cities);
}

void test_travelInShortestPath_given_10_city_should_get_the_shortest_travel_path(void){
  City tenCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ };

  City  cityA1 = cityA, cityB1 = cityB, cityC1 = cityC, cityD1 = cityD, cityE1 = cityE,
        cityF1 = cityF, cityG1 = cityG, cityH1 = cityH, cityI1 = cityI, cityJ1 = cityJ;
  
  City *head1 =  cityListNew(&cityA);
  addCityList(&head1, &cityB);
  addCityList(&head1, &cityC);
  addCityList(&head1, &cityD);
  addCityList(&head1, &cityE);
  addCityList(&head1, &cityF);
  addCityList(&head1, &cityG);
  addCityList(&head1, &cityH);
  addCityList(&head1, &cityI);
  addCityList(&head1, &cityJ);
  addCityList(&head1, &cityA);
  
  City *head2 =  cityListNew(&cityF1);
  addCityList(&head2, &cityJ1);
  addCityList(&head2, &cityC1);
  addCityList(&head2, &cityA1);
  addCityList(&head2, &cityE1);
  addCityList(&head2, &cityB1);
  addCityList(&head2, &cityD1);
  addCityList(&head2, &cityG1);
  addCityList(&head2, &cityI1);
  addCityList(&head2, &cityH1);
  addCityList(&head2, &cityF1);
  
  travelInShortestPath( head1, head2, tenCity);
}
