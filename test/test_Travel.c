#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"
#include <stdlib.h>
#include "LinkedList.h"
#include "mock_Random.h"

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

void test_copycity_given_pointer_cityB_should_copy_and_hold_the_city(void){
  City *head =  cityListNew(&cityB);
  City clone = copyCity(*head);
  clearCityList(head);
  TEST_ASSERT_EQUAL( clone.ID  , cityB.ID);
}

/**
*
*   Original:   CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH
*                                                     |  copy
*   Clone   :   CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH
*
*/
void test_copyPath_should_copy_and_hold_the_cities_list(void){
  City arr[8], *head;
  head =  cityListNew(&cityA);
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

  Path clonePath = copyPath(path , arr);
  clearCityList(head);
  TEST_ASSERT_EQUAL( clonePath.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->ID                                    , cityC.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->ID                  , cityF.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
  clearCityList(path.cities);
}

/**
*-----------------------------------------------------------------------------------
* 1.Original Path               $                                                   *
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
void test_MutationCities_given_cityB_and_cityF_as_target_should_do_mutation_of_the_link(void){
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

  path = MutationCities(path, cityB, cityF);
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
* 2. select cityA and cityC as target , reverse the link between them               *
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
void test_MutationCities_given_2_near_city_should_do_mutation_of_the_link(void){
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

  path = MutationCities(path, cityA, cityC);
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
void test_MutationCities_given_2_besides_city_should_do_nothing(void){
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

  path = MutationCities(path, cityA, cityB);
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
*                     $  $
*                   cityA--->cityB-->cityC--->cityD
*                     ^                          |
*                     |                          v
*                  cityH<---cityG<---cityF<---cityE
*/
void test_MutationCities_given_2_same_city_should_directly_return(void){
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

  path = MutationCities(path, cityA, cityA);
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
void test_checkingFor2opt_given_cityA_cityC_should_no_do_2opt_because_they_cant_produce_better_chromesome(void){
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

  int ans = checkingFor2opt(head, cityA, cityC);
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
*                should  do 2opt because can get shorter distance
*/
void test_checkingFor2opt_given_cityA_cityF_should_do_2opt_because_they_produce_better_chromesome(void){
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

  int ans = checkingFor2opt(head, cityA, cityF);
  TEST_ASSERT_EQUAL(ans , 1);
  clearCityList(head);
}

void test_checkingFor2opt_given_same_city_to_do_2opt_should_return_0(void){
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

  int ans = checkingFor2opt(head, cityC, cityC);
  TEST_ASSERT_EQUAL(ans , 0);
  clearCityList(head);
}

void test_checkIsCityNotUsed_given_array_A_B_C_and_put_in_cityD_should_return_1_because_cityD_is_not_inside(void){
  City arr[] = { cityA, cityB, cityC };

  int ans = checkIsCityNotUsed( arr, cityD, 4);
  TEST_ASSERT_EQUAL( ans, 1);
}

void test_checkIsCityNotUsed_given_array_A_B_C_and_put_in_cityA_should_return_0_because_cityA_is_inside(void){
  City arr[] = { cityA, cityB, cityC };

  int ans = checkIsCityNotUsed( arr, cityA, 4);
  TEST_ASSERT_EQUAL( ans, 0);
}

void test_getFrontCity_given_linkedList_B_E_C_A_G_and_target_G_should_get_cityA(void){
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

void test_getBackCity_given_linkedList_B_E_C_A_G_and_target_C_should_get_cityA(void){
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

void test_addCityToFront_given_a_city_array_A_H_I_and_add_D_to_front_should_become_D_A_H_I(void){
  City arr[4] = { cityA, cityH, cityI};

  addCityToFront( arr, cityD, 4);
  TEST_ASSERT_EQUAL ( arr[0].ID, cityD.ID);
  TEST_ASSERT_EQUAL ( arr[1].ID, cityA.ID);
  TEST_ASSERT_EQUAL ( arr[2].ID, cityH.ID);
  TEST_ASSERT_EQUAL ( arr[3].ID, cityI.ID);
}

void test_addCityToBack_given_a_city_array_A_H_I_and_add_D_to_front_should_become_A_H_I_D(void){
  City arr[4] = { cityA, cityH, cityI};

  addCityToBack( arr, cityD, 4, cityI.ID);
  TEST_ASSERT_EQUAL ( arr[0].ID, cityA.ID);
  TEST_ASSERT_EQUAL ( arr[1].ID, cityH.ID);
  TEST_ASSERT_EQUAL ( arr[2].ID, cityI.ID);
  TEST_ASSERT_EQUAL ( arr[3].ID, cityD.ID);
}

void test_convertArrayToPath_given_array_A_B_C_D_E_should_convert_to_path__A_B_C_D_E_(void){
  City arr[] = {cityA, cityB, cityC, cityD, cityE};

  Path path = convertArrayToPath( arr, 5);
  TEST_ASSERT_EQUAL( path.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                    , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                  , cityA.ID);
}

void test_bubbleSortForNeighBour_given_an_NeighBour_array_should_sort_according_distance(void){
  NeighBour neigh1, neigh2, neigh3;
  neigh1.distance = 5.34 , neigh2.distance = 9.12 , neigh3.distance = 3.55 ;
  neigh1.neighBour = cityA, neigh2.neighBour = cityB , neigh3.neighBour = cityC;
  NeighBour arr[] = { neigh1, neigh2, neigh3 };

  bubbleSortForNeighBour( arr, 3);
  TEST_ASSERT_EQUAL ( arr[0].neighBour.ID, neigh3.neighBour.ID);
  TEST_ASSERT_EQUAL ( arr[1].neighBour.ID, neigh1.neighBour.ID);
  TEST_ASSERT_EQUAL ( arr[2].neighBour.ID, neigh2.neighBour.ID);
}

void test_bubbleSortForPath_given_path1_distance_100_path2_distance_50_path3_distance_70_should_sort_according_ditance(void){
  Path path1, path2, path3;
  path1.distance = 100;
  path2.distance = 50;
  path3.distance = 70;

  Path array[] = { path1, path2, path3 };
  bubbleSortForPath ( array , 3);
  TEST_ASSERT_EQUAL ( array[0].distance, path2.distance);
  TEST_ASSERT_EQUAL ( array[1].distance, path3.distance);
  TEST_ASSERT_EQUAL ( array[2].distance, path1.distance);
}

/**------------------------------------------------------------------------------------------
* 1. During my crossover function processing, after the condition break,
*   it will produce a crossover array, but the array is missing some element,
*   so it need to fill rest of element behind
*
* 2. given array and linked list shown  below, cityC and cityE is missing inside the array,
*
*         arr                                    LinkedList
*   cityB--CityD--cityA                   cityA--CityB--cityC--CityD--cityE
*                   *                                      *             *
*
* 3. so should add cityC and cityE into the array behind cityA, but for efficient of computing,
*    the adding sequence should add according the distance between cityA, which is neighbour
*
* 4. The city is add inside the array according distance of neighbour
*   cityB--CityD--cityA--cityE--cityC
*                     Neighbour Neighbour
* --------------------------------------------------------------------------------------------
*/
void test_addCityOfNeighbour_given_array_and_it_want_to_add_mising_element_from_LinkedList_should_add_the_city_according_neighBour(void){
  City  cityA1 = cityA, cityB1 = cityB, cityD1 = cityD;
  City arr[] = { cityB1, cityD1 , cityA1 };
  City *head1 =  cityListNew(&cityA);
  addCityList(&head1, &cityB);
  addCityList(&head1, &cityC);
  addCityList(&head1, &cityD);
  addCityList(&head1, &cityE);
  addCityList(&head1, &cityA);

  addCityOfNeighbour( arr, cityA, &cityB, cityA.ID, 5);
  TEST_ASSERT_EQUAL ( arr[0].ID, cityB.ID);
  TEST_ASSERT_EQUAL ( arr[1].ID, cityD.ID);
  TEST_ASSERT_EQUAL ( arr[2].ID, cityA.ID);
  TEST_ASSERT_EQUAL ( arr[3].ID, cityE.ID);
  TEST_ASSERT_EQUAL ( arr[4].ID, cityC.ID);
  clearCityList(head1);
}

/**--------------------------------------------------------------------------------------------------------
* 1) The 2 chromosome cities shown below, and cityE is choose to do crossover ,                           *
*     it should break loop at cityB                                                                       *
*                                                                                                         *
*                    -----------left-----------------$$$$$                                                *
*     CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH              *
*                  same                                                                                   *
*                                                                                                         *
*                              $$$$$ ---------Right-------------                                          *
*      CityC------> CityD----->CityE----->CityH------>CityG----->CityB----->CityF------>CityA             *
*                                                                 same                                    *
*                                                                                                         *
*----------------------------------------------------------------------------------------------------------
* 2) Select cityE as mid, fill the city 1by1 from chromose1'left and chromose2'Right,                     *
*    if the coming cityB is is already exists, then stop and form a crossover link                        *
*                                                                                                         *
*                                                mid                                                      *
*             CityB----->CityC------>CityD----->CityE----->CityH------>CityG   (cityB)                    *
*                                                                                                         *
*                                                                                                         *
*----------------------------------------------------------------------------------------------------------
*  3) add the rest of city to behind cityG, the added city's sequence is based of the distance to cityG   *
*                                                             $                                           *
*  CityB----->CityC------>CityD----->CityE----->CityH------>CityG------>CityF------->cityA                *
*                                                                       (near  to    far )                *
*                                                                                                         *
*---------------------------------------------------------------------------------------------------------*/
void test_corssoverCities_given_2_cities_and_choose_cityE_should_do_crossover_and_form_new_cities(void){
  City arr1[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH };
  City arr2[] = { cityC,cityD,cityE,cityH,cityG,cityB,cityF,cityA };
  City array[8];
  clearCityArray( array, 8);  // To ensure the array is empty element, because sometimes it will randomly generate some value
  Path path1 = convertArrayToPath( arr1, 8);
  Path path2 = convertArrayToPath( arr2, 8);
  Path cross;
  path1.size   = 8;
  path2.size   = 8;

  cross = crossoverCities(path1, path2, cityE, array);
  clearCityList(path1.cities);
  clearCityList(path2.cities);
  TEST_ASSERT_EQUAL( cross.cities->ID                                                , cityB.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->ID                                          , cityC.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->ID                                    , cityD.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->ID                              , cityE.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->ID                        , cityH.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->ID                  , cityG.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->next->ID            , cityF.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->next->next->ID      , cityA.ID);
  clearCityList(cross.cities);
}

/**----------------------------------------------------------------------------------------------------------
* 1) The 2 chromosome cities shown below, and cityA is choose to do crossover                               *
*     it should break loop at cityE                                                                         *
*      $$$$$                                              ------------left-----------------                 *
*     CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH                *
*                                                    same                                                   *                                                                                                       *
*      ---------Right-------------                                                      $$$$$               *
*      CityC------> CityD----->CityE----->CityH------>CityG----->CityB----->CityF------>CityA               *
*                               same                                                                        *                                                                                                          *
*------------------------------------------------------------------------------------------------------------
* 2) Select cityA as mid, fill the city 1by1 from chromose1'left and chromose2'Right,                       *
*    if the coming city is is already exists, then stop and form a crossover link                           *
*                                                                                                           *
*                                          mid                                                              *
*   (CityE)  CityF----->CityG------>CityH----->CityA------>CityC----->CityD------>CityE                     *
*                                                                                                           *                                                                                                          *
*------------------------------------------------------------------------------------------------------------
*  3) add the rest of city to behind                                                                        *
*                                                                                                           *
*  CityF----->CityG------>CityH----->CityA------>CityC----->CityD------>CityE----->CityB                    *
*                                                                                                           *
*                                                                                                           *
*-----------------------------------------------------------------------------------------------------------*/
void xtest_corssoverCities_given_2_cities_and_choose_cityA_should_do_crossover_and_form_new_cities(void){
  City arr1[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH };
  City arr2[] = { cityC,cityD,cityE,cityH,cityG,cityB,cityF,cityA };
  City array[8];
  clearCityArray( array, 8);
  Path path1 = convertArrayToPath( arr1, 8);
  Path path2 = convertArrayToPath( arr2, 8);
  Path cross;
  path1.size   = 8;
  path2.size   = 8;

  cross = crossoverCities(path1, path2, cityA, array);
  clearCityList(path1.cities);
  clearCityList(path2.cities);
  TEST_ASSERT_EQUAL( cross.cities->ID                                                , cityF.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->ID                                          , cityG.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->ID                                    , cityH.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->ID                              , cityA.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->ID                        , cityC.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->ID                  , cityD.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->next->ID            , cityE.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->next->next->ID      , cityB.ID);
  clearCityList(cross.cities);
}

void test_InitPathFromTheGivenArray_given_a_sampleArray_should_init_the_path_and_use_the_local_array_as_element(void){
  City localArr[]= { cityA, cityB, cityC, cityD, cityE, cityF, cityG, cityH, cityI, cityJ }, 
       sampleArr[]={ cityA, cityD, cityC, cityB, cityE, cityI, cityH, cityJ, cityG, cityF } ;
  Path path;
  
  path = InitPathFromTheGivenArrayByUsingLocalElement( sampleArr, localArr, 10);
  clearCityArray( sampleArr, 10);
  TEST_ASSERT_EQUAL( path.cities->ID                                                      , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                                , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                          , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                                    , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                              , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                        , cityI.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->ID                  , cityH.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->ID            , cityJ.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->next->ID      , cityG.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->next->next->ID, cityF.ID);
  clearCityList(path.cities);
}

void test_initPopulationTable_given_population_size_15_and_cities_size_10_should_set_the_population_table_randomize_accroding_10x15(void){
  int sizeOfPopulation = 15, sizeOfCity = 10;
  City tenCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ };
  Path population[sizeOfPopulation];
  City tour[sizeOfPopulation][sizeOfCity];

  initPopulationTable( population, tenCity, sizeOfPopulation, sizeOfCity);
  //printfOutPopulatointable( population, sizeOfPopulation);
  freePopulationTable( population, sizeOfPopulation);
}

void test_initPopulationTable_given_population_size_20_and_cities_size_10_should_set_the_population_table_randomize_accroding_10x20(void){
  int sizeOfPopulation = 20, sizeOfCity = 10;
  City tenCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ };
  Path population[sizeOfPopulation];
  City tour[sizeOfPopulation][sizeOfCity];

  initPopulationTable( population, tenCity, sizeOfPopulation, sizeOfCity);
  //printfOutPopulatointable( population, sizeOfPopulation);
  freePopulationTable( population, sizeOfPopulation);
}

/**
*10|   G(2,10)
*  |
* 9|                                      C(10,9)
*  |
* 8|           H(4,8)
*  |
* 7|                *B(5,7)
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
*  |______________________________________________> x
* 0   1   2   3   4   5   6   7   8   9   10  11 
*
* This function is used to support mutation process, to let the process will ways choose the near distance of mutation city
* Given the target is cityB, and choose 3 city , so cityB will locate the 3 mutation target of cityH,F,E,which are near distance to cityB, 
* For the complete mutation functions, the number of city to do mutated will be calculate by certain percentage 
*/
void test_locateNeighBoursBasedOnGivenNumber_choose_cityB_given_3_city_should_locate_cityH_cityG_cityE_as_neighbour(void){
  int  sizeOfCity = 10, numOfTargetCity = 3;
  City tenCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ }, shortDistanceArr[numOfTargetCity];
  
  locateNeighBoursBasedOnGivenNumber( shortDistanceArr, tenCity, cityB, numOfTargetCity, sizeOfCity);
  TEST_ASSERT_EQUAL ( shortDistanceArr[0].ID, cityH.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[1].ID, cityF.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[2].ID, cityE.ID);
}

void test_locateNeighBoursBasedOnGivenNumber_choose_cityA_given_4_city_should_locate_cityF_cityD_cityB_cityH_as_neighbour(void){
  int  sizeOfCity = 10, numOfTargetCity = 4;
  City tenCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ }, shortDistanceArr[numOfTargetCity];
  
  locateNeighBoursBasedOnGivenNumber( shortDistanceArr, tenCity, cityA, numOfTargetCity, sizeOfCity);
  TEST_ASSERT_EQUAL ( shortDistanceArr[0].ID, cityF.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[1].ID, cityD.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[2].ID, cityB.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[3].ID, cityH.ID);
}

void test_locateNeighBoursBasedOnGivenNumber_choose_cityJ_given_5_city_should_locate_cityE_cityI_cityD_cityC_cityB_as_neighbour(void){
  int  sizeOfCity = 10, numOfTargetCity = 5;
  City tenCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ }, shortDistanceArr[numOfTargetCity];
  
  locateNeighBoursBasedOnGivenNumber( shortDistanceArr, tenCity, cityJ, numOfTargetCity, sizeOfCity);
  TEST_ASSERT_EQUAL ( shortDistanceArr[0].ID, cityE.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[1].ID, cityI.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[2].ID, cityD.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[3].ID, cityC.ID);
  TEST_ASSERT_EQUAL ( shortDistanceArr[4].ID, cityB.ID);
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
* 2. select cityA and cityF as target , reverse the link between them               *
*                                                                                   *
*                                                                                   *
*                                 NULL                                              *
*                                 ^                                                 *
*                                 |                                                 *
*                   (cityA)--->cityB<---cityC<---cityD                              *
*                     ^                            ^                                *
*                     |                            |                                *
*                  cityH<---cityG   (cityF)----->cityE                              *
*                                                                                   *
*-----------------------------------------------------------------------------------*
* 3.Mutation                                                                        *
*                                                                                   *
*                      ----->cityA      cityB<---cityC --                           *
*                     |          \    /                 |                           *
*                     |           \ /                   |                           *
*                     |           / \                   |                           *
*                     |          v   v                  v                           *
*                  cityH<---cityG    cityF--->cityE--->cityD                        *
*-----------------------------------------------------------------------------------*
*/
void test_mock_doMutation_given_mock_the_random_city_as_cityA_and_cityF_should_do_mutate(void){
  int size = 8;
  City eightCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH};
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
  
  random_ExpectAndReturn ( 8 , 0 );
  random_ExpectAndReturn ( 2 , 0 );
  path = mock_doMutation( path, eightCity, size);
  TEST_ASSERT_EQUAL( path.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( path.cities->next->ID                                          , cityF.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->ID                                    , cityE.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->ID                        , cityC.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->ID                  , cityB.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( path.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
  clearCityList(head);
  clearCityList(path.cities);
}

/**--------------------------------------------------------------------------------------------------------
* 1) The 2 chromosome cities shown below, and cityE is choose to do crossover ,                           *
*     it should break loop at cityB                                                                       *
*                                                                                                         *
*                    -----------left-----------------$$$$$                                                *
*     CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH              *
*                  same                                                                                   *
*                                                                                                         *
*                              $$$$$ ---------Right-------------                                          *
*      CityC------> CityD----->CityE----->CityH------>CityG----->CityB----->CityF------>CityA             *
*                                                                 same                                    *
*                                                                                                         *
*----------------------------------------------------------------------------------------------------------
* 2) Select cityE as mid, fill the city 1by1 from chromose1'left and chromose2'Right,                     *
*    if the coming cityB is is already exists, then stop and form a crossover link                        *
*                                                                                                         *
*                                                mid                                                      *
*             CityB----->CityC------>CityD----->CityE----->CityH------>CityG   (cityB)                    *
*                                                                                                         *
*                                                                                                         *
*----------------------------------------------------------------------------------------------------------
*  3) add the rest of city to behind cityG, the added city's sequence is based of the distance to cityG   *
*                                                             $                                           *
*  CityB----->CityC------>CityD----->CityE----->CityH------>CityG------>CityF------->cityA                *
*                                                                       (near  to    far )                *
*                                                                                                         *
*---------------------------------------------------------------------------------------------------------*/
void test_mock_doCrossover_given_mock_the_random_city_as_cityE_should_do_crossover_and_form_new_cities(void){
  City arr1[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH };
  City arr2[] = { cityC,cityD,cityE,cityH,cityG,cityB,cityF,cityA };
  City array[8];
  clearCityArray( array, 8);  // To ensure the array is empty element, because sometimes it will randomly generate some value 
  Path path1 = convertArrayToPath( arr1, 8);
  Path path2 = convertArrayToPath( arr2, 8);
  Path cross;
  path1.size   = 8;
  path2.size   = 8;

  random_ExpectAndReturn ( 8 , 4 );
  cross = mock_doCrossover( path1, path2, arr1, array, 8);
  clearCityList(path1.cities);
  clearCityList(path2.cities);
  TEST_ASSERT_EQUAL( cross.cities->ID                                                , cityB.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->ID                                          , cityC.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->ID                                    , cityD.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->ID                              , cityE.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->ID                        , cityH.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->ID                  , cityG.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->next->ID            , cityF.ID);
  TEST_ASSERT_EQUAL( cross.cities->next->next->next->next->next->next->next->ID      , cityA.ID);
  clearCityList(cross.cities);
}

void test_solveTSP_given_10_City_15_population_20_maxNumGeneration_should_find_the_shortest_travel_path(void){
  int sizeOfPopulation = 15, sizeOfCity = 10, maxNumGeneration = 20;
  City tenCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ };

  printf("\nGiven 10 city , 15 population, 20 maxNumGeneration\n");
  Path shortestPath = solveTSP( tenCity, sizeOfPopulation, sizeOfCity, maxNumGeneration);
}

void test_solveTSP_given_20_City_15_population_20_maxNumGeneration_should_find_the_shortest_travel_path(void){
  int sizeOfPopulation = 15, sizeOfCity = 20, maxNumGeneration = 20;
  City twentyCity[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ,
                        cityK,cityL,cityM,cityN,cityO,cityP,cityQ,cityR,cityS,cityT};

  printf("\nGiven 20 city , 15 population, 20 maxNumGeneration\n");
  Path shortestPath = solveTSP( twentyCity, sizeOfPopulation, sizeOfCity, maxNumGeneration);
}
