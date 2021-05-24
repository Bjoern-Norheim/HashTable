#include "linkedList.h"
#include <stdlib.h>

#define NUM_BUCKETS 20
#define NO_VALUE ((valueType)-92515325)

typedef struct hashTable{
linkedList* bucketArray;

}hashTable;

int hash(int key);
hashTable ht_initalizeHashTable();
void ht_setValue(int key, valueType newValue, hashTable* ht);
valueType ht_getValue(int key, hashTable* ht);