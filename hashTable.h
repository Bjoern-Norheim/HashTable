#include "linkedList.h"
#define NUM_BUCKETS 20

typedef struct hashTable{
linkedList* bucketArray;

}hashTable;

int hash(int key);