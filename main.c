#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
///// 
#define KVPAIR_TEST ((kvPair){1, 1})
// <condition> ? <if true> : <if false>; turnery statement
// Test writing to and getting a value back at a key
void testHashTable_testSetGet(int key, hashTable *ht) {
  valueType setValue = key * 10;
  valueType firstGet = ht_getValue(key, ht);
  ht_setValue(key, setValue, ht);
  valueType secondGet = ht_getValue(key, ht);
  firstGet == NO_VALUE ? printf("Test Passed\n") : printf("Test Failed with key: %d\n", key);
  secondGet == setValue ? printf("Test Passed\n") : printf("Test Failed, returned value: %d\n", secondGet);
}

void testHashTable() {
  printf("\nHash Table Test\n");
  hashTable newHT = ht_initalizeHashTable();
  testHashTable_testSetGet(99, &newHT);
  /*ht_getValue(99, &newHT);// Should be null
  ht_setValue(99, 2, &newHT);
  ht_getValue(99, &newHT); // Should be 2*/

}

void testLinkedList() {
  printf("\n Linked List Test\n");
  printf("\nZero Array Test\n");
  linkedList zeroArray = ll_initializeArray(0);
  ll_getSize(zeroArray);
  ll_append(&zeroArray, KVPAIR_TEST);
  ll_getSize(zeroArray);

  printf("\nOne Array Test\n");
  linkedList oneArray = ll_initializeArray(1);
  ll_getSize(oneArray);
  ll_append(&oneArray, KVPAIR_TEST);
  ll_getSize(oneArray);

  printf("\nMisc Array Test\n");
  linkedList newArr = ll_initializeArray(8);
  ll_getSize(newArr);
  ll_setValue(&newArr, KVPAIR_TEST, 3);
  ll_getValue(&newArr, 3);
  ll_append(&newArr, KVPAIR_TEST);
  ll_getSize(newArr);
}

int main(void) {
  testLinkedList();

  testHashTable();

  return 0;
}