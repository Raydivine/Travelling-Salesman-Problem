#include "unity.h"
#include "LinkedList.h"
#include "CityCoordinate.h"
#include "InitCity.h"

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

void tearDown(void) {}

void test_linkListNew_should_create_city_linkedList(void) {
  City *cities = cityListNew(&cityA);
  TEST_ASSERT_NOT_NULL(cities);
  TEST_ASSERT_EQUAL( cities->ID, cityA.ID);
  clearCityList(cities);
}
/**         cityJ add cityA, cityB, cityC, cityJ
*                           |   should form link
*                           v
*             cityJ->cityA->cityB->cityC->cityJ->NULL
*/             
void test_addCityList_given_create_cityJ_as_head_and_add_cityB_cityC_cityD_should_add_to_citylist(void) {
  City *head =  cityListNew(&cityJ);
 
  addCityList(&head, &cityA);
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityJ);
  addCityList(&head, NULL);
  
  TEST_ASSERT_EQUAL( head->ID                        , cityJ.ID);
  TEST_ASSERT_EQUAL( head->next->ID                  , cityA.ID);
  TEST_ASSERT_EQUAL( head->next->next->ID            , cityB.ID);
  TEST_ASSERT_EQUAL( head->next->next->next->ID      , cityC.ID);
  TEST_ASSERT_EQUAL( head->next->next->next->next->ID, cityJ.ID);
  TEST_ASSERT_NULL ( head->next->next->next->next->next);
  
  clearCityList(head);
}

/**                               
*             cityJ--->cityA-->cityB--->cityC--->NULL 
*                                  |
*                                  v
*            NULL<----cityJ<---cityA<---cityB<---cityC
*/             
void test_reverseLinkedList_should_reverse_the_cities_link_from_J_A_B_C_to_C_B_A_J (void) {
  City *head =  cityListNew(&cityJ);
  addCityList(&head, &cityA);
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, NULL);
  
  reverseLinkedList(head);
  TEST_ASSERT_EQUAL( head->ID , cityJ.ID);
  TEST_ASSERT_EQUAL( cityA.next->ID, cityJ.ID );
  TEST_ASSERT_EQUAL( cityB.next->ID, cityA.ID );
  TEST_ASSERT_EQUAL( cityC.next->ID, cityB.ID );
  TEST_ASSERT_NULL ( cityJ.next);
  clearCityList(head);
}

/**                          $     
*                   cityA--->cityB-->cityC--->cityD 
*                     ^                          |               
*                     |      $                   v                   
*                  cityH<---cityG<---cityF<---cityE   
*                                 
*  select cityB and cityG as target , reverse the link between them
*
*                             $
*                   cityA--->cityB<---cityC<---cityD 
*                     ^                          ^               
*                     |     $                    |                   
*                  cityH<---cityG---->cityF--->cityE                    
*/ 
void test_reverseTheLinkBetween2City_select_cityB_and_cityG_should_reverse_the_link_betweeen_them(void){
  City *head =  cityListNew(&cityA);  // assign cityA as head
  addCityList(&head, &cityB);
  addCityList(&head, &cityC);
  addCityList(&head, &cityD);
  addCityList(&head, &cityE);
  addCityList(&head, &cityF);
  addCityList(&head, &cityG);
  addCityList(&head, &cityH);  
  cityH.next = head; 
  reverseTheLinkBetween2City(head, &cityB, &cityG);
}