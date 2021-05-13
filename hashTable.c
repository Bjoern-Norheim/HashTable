#include "hashTable.h"

int hash(int key){
 return key % NUM_BUCKETS;
}