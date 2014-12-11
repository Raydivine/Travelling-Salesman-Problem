#include "unity.h"
#include "Travel.h"
#include "CityCoordinate.h"
#include "InitCity.h"
#include <stdlib.h>
#include "LinkedList.h"

City cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ,
     cityK,cityL,cityM,cityN,cityO,cityP,cityQ,cityR,cityS,cityT;
City allCities[20];

City  goA[20], goB[20], goC[20], goD[20], goE[20], goF[20], goG[20], goH[20] , goI[20], goJ[20],
      goK[20], goL[20], goM[20], goN[20], goO[20], goP[20], goQ[20], goR[20] , goS[20], goT[20];

Locate locate[20];

// City  *goA[20], *goB[20], *goC[20], *goD[20], *goE[20], *goF[20], *goG[20], *goH[20] , *goI[20], *goJ[20],
      // *goK[20], *goL[20], *goM[20], *goN[20], *goO[20], *goP[20], *goQ[20], *goR[20] , *goS[20], *goT[20];

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
  
  allCities[0] = cityA;
  allCities[1] = cityB;
  allCities[2] = cityC;
  allCities[3] = cityD;
  allCities[4] = cityE;
  allCities[5] = cityF;
  allCities[6] = cityG;
  allCities[7] = cityH;
  allCities[8] = cityI;
  allCities[9] = cityJ;
  allCities[10] = cityK;
  allCities[11] = cityL;
  allCities[12] = cityM;
  allCities[13] = cityN;
  allCities[14] = cityO;
  allCities[15] = cityP;
  allCities[16] = cityQ;
  allCities[17] = cityR;
  allCities[18] = cityS;
  allCities[19] = cityT;
  
  destinationDistanceArray( cityA, goA, allCities, 20);
  destinationDistanceArray( cityB, goB, allCities, 20);
  destinationDistanceArray( cityC, goC, allCities, 20);
  destinationDistanceArray( cityD, goD, allCities, 20);
  destinationDistanceArray( cityE, goE, allCities, 20);
  destinationDistanceArray( cityF, goF, allCities, 20);
  destinationDistanceArray( cityG, goG, allCities, 20);
  destinationDistanceArray( cityH, goH, allCities, 20);
  destinationDistanceArray( cityI, goI, allCities, 20);
  destinationDistanceArray( cityJ, goJ, allCities, 20);
  destinationDistanceArray( cityK, goK, allCities, 20);
  destinationDistanceArray( cityL, goL, allCities, 20);
  destinationDistanceArray( cityM, goM, allCities, 20);
  destinationDistanceArray( cityN, goN, allCities, 20);
  destinationDistanceArray( cityO, goO, allCities, 20);
  destinationDistanceArray( cityP, goP, allCities, 20);
  destinationDistanceArray( cityQ, goQ, allCities, 20);
  destinationDistanceArray( cityR, goR, allCities, 20);
  destinationDistanceArray( cityS, goS, allCities, 20);
  destinationDistanceArray( cityT, goT, allCities, 20);
  
  // allCities[] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ,
                  // cityK,cityL,cityM,cityN,cityO,cityP,cityQ,cityR,cityS,cityT };
}

//allCities[20] = { cityA,cityB,cityC,cityD,cityE,cityF,cityG,cityH,cityI,cityJ,cityK,cityL,cityM,cityN,cityO,cityP,cityQ,cityR,cityS,cityT };
void tearDown(void){}
  
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

void test_destinationDistanceArray_given_target_cityA_should_return_array_accord_distance_of_F_D_B_H_E(void){

  City goA[20];
  destinationDistanceArray( cityA, goA, allCities, 20);
  TEST_ASSERT_EQUAL ( goA[0].ID, cityF.ID);
  TEST_ASSERT_EQUAL ( goA[1].ID, cityD.ID);
  TEST_ASSERT_EQUAL ( goA[2].ID, cityB.ID);
  TEST_ASSERT_EQUAL ( goA[3].ID, cityH.ID);
  TEST_ASSERT_EQUAL ( goA[4].ID, cityE.ID);
  TEST_ASSERT_EQUAL ( goA[18].ID, cityK.ID);
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


void test_get10shortestCity_given_cityA_should_get_the_front_10_elements_from_cityA_array(void){ 

  City bestCities[10];
  get10shortestCity(bestCities, cityA, allCities, 20);
  TEST_ASSERT_EQUAL ( bestCities[0].ID, cityF.ID);
  TEST_ASSERT_EQUAL ( bestCities[1].ID, cityD.ID);
  TEST_ASSERT_EQUAL ( bestCities[2].ID, cityB.ID);
  TEST_ASSERT_EQUAL ( bestCities[3].ID, cityH.ID);
  TEST_ASSERT_EQUAL ( bestCities[4].ID, cityE.ID);
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

/**
*
*   Original:   CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH
*                                                     |  copy
*   Clone   :   CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH
*
*/
void test_copyCities_should_copy_a_new_cities_list(void){
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

  Path clonePath = copyCities(path);
  TEST_ASSERT_EQUAL( clonePath.cities->ID                                                , cityA.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->ID                                          , cityB.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->ID                                    , cityC.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->ID                              , cityD.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->ID                        , cityE.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->ID                  , cityF.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->ID            , cityG.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->next->ID      , cityH.ID);
  TEST_ASSERT_EQUAL( clonePath.cities->next->next->next->next->next->next->next->next->ID, cityA.ID);
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
  addCityList(&head, &cityA);
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
*-----------------------------------------------------------------------------------
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
*-----------------------------------------------------------------------------------*
*/
void test_MutationOfCities_given_2_near_city_should_do_reverse(void){
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

  path = MutationOfCities(path, &cityA, &cityC);
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


/**
*-----------------------------------------------------------------------------------*
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
*-----------------------------------------------------------------------------------*
*/
void test_MutationOfCities_given_2_besides_city_should_do_nothing(void){
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

  path = MutationOfCities(path, &cityA, &cityB);
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
void test_MutationOfCities_given_2_same_city_should_directly_return(void){
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

  path = MutationOfCities(path, &cityA, &cityA);
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
void test_checkingFor2opt_given_cityA_cityG_should_no_do_2opt_because_they_cant_produce_better_chromesome(void){
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
void test_checkingFor2opt_given_cityA_cityG_should_do_2opt_because_they_produce_better_chromesome(void){
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

  int ans = checkingFor2opt(&cityA, &cityA);
  TEST_ASSERT_EQUAL(ans , 0);
  clearCityList(head);
}

void test_checkIsCityUsed_given_array_100_101_102_88_233_123_999_and_target_103_should_return_1(void){
  int ans, arr[] = { 100,101,102,88,233,123,999 };
 
  ans = checkIsCityUsed(arr,103,7);
  TEST_ASSERT_EQUAL(ans , 1);
}

void test_checkIsCityUsed_given_array_100_101_102_88_233_123_999_and_target_102_should_return_0(void){
  int ans, arr[] = { 100,101,102,88,233,123,999 };
 
  ans = checkIsCityUsed(arr,102,7);
  TEST_ASSERT_EQUAL(ans , 0);
}

/**
*-----------------------------------------------------------------------------------------------------------
* 1) The 2 chromosome cities shown below, and cityE is choose to do crossover                               *
*                                                                                                           *
*      ----------------left-------------------       $$$$$                                                  *
*     CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH                *
*                                                                                                           *
*                                                                                                           *
*                              $$$$$       ----------------Right-------------------                         *
*      CityC------> CityD----->CityE----->CityH------>CityG----->CityB----->CityF------>CityA               *
*                                                                                                           *
*                                                                                                           *
*------------------------------------------------------------------------------------------------------------
* 2) Select cityE as mid, fill the city 1by1 from chromose1'left and chromose2'Right,                       *
*    if the coming city is is already exists, then stop and form a crossover link                           *
*                                                                                                           *
*                                                                                                           *
*             CityB----->CityC------>CityD----->CityE----->CityH------>CityG                                *
*                                                                                                           *
*                                                                                                           *                                                                                                                                                                                                                                                                                                                                                                                                                                             
*------------------------------------------------------------------------------------------------------------
*  3) add the rest of city to behind                                                                        *
*                                                                                                           *
*  CityE----->CityH------>CityG----->CityB----->CityF------>CityA----->CityC------>CityD----->CityE         *
*                                                                                                           *
*                                                                                                           *
*------------------------------------------------------------------------------------------------------------
*/
void test_corssoverCities_given_2_cities_and_choose_cityE_should_do_crossover_and_form_new_cities(void){
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
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->next->next->next->ID, cityB.ID);
  clearCityList(head1);
  //clearCityList(head2);
  clearCityList(crossoverPath.cities);
}


/**
*-----------------------------------------------------------------------------------------------------------
* 1) The 2 chromosome cities shown below, and cityE is choose to do crossover                               *
*                                                                                                           *
*      $$$$$                                                                                                *
*     CityA------> CityB----->CityC------>CityD----->CityE----->CityF------>CityG----->CityH                *
*                                                                                                           *
*                                                                                                           *
*                                                                                       $$$$$               *
*      CityC------> CityD----->CityE----->CityH------>CityG----->CityB----->CityF------>CityA               *
*                                                                                                           *
*                                                                                                           *
*------------------------------------------------------------------------------------------------------------
* 2) Select cityE as mid, fill the city 1by1 from chromose1'left and chromose2'Right,                       *
*    if the coming city is is already exists, then stop and form a crossover link                           *
*                                                                                                           *
*                                                                                                           *
*    CityF----->CityG------>CityH----->CityA------>CityC----->CityD------>CityE                             *
*                                                                                                           *
*                                                                                                           *                                                                                                                                                                                                                                                                                                                                                                                                                                             
*------------------------------------------------------------------------------------------------------------
*  3) add the rest of city to behind                                                                        *
*                                                                                                           *
*  CityE----->CityH------>CityG----->CityB----->CityF------>CityA----->CityC------>CityD----->CityE         *
*                                                                                                           *
*                                                                                                           *
*------------------------------------------------------------------------------------------------------------
*/
void test_corssoverCities_given_2_cities_and_choose_cityA_should_do_crossover_and_form_new_cities(void){
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
  TEST_ASSERT_EQUAL( crossoverPath.cities->next->next->next->next->next->next->next->next->ID, cityF.ID);
  
  clearCityList(head1);
  //clearCityList(head2);
  clearCityList(crossoverPath.cities);
}










