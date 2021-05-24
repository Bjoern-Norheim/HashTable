#include "hashTable.h"
#include <stdio.h>

int hash(int key){
 return key % NUM_BUCKETS;
}

hashTable ht_initalizeHashTable() {
  hashTable ht;
  ht.bucketArray = (linkedList*)malloc(NUM_BUCKETS * sizeof(linkedList*));
  for(int i =0; i < NUM_BUCKETS;i ++){
    ht.bucketArray[i] = ll_initializeArray(0);
  }
  return ht;
}

void ht_setValue(int requestedKey, valueType newValue, hashTable* ht) {
  node* node;
  int bucketNum = hash(requestedKey);
  linkedList bucket = ht->bucketArray[bucketNum];
  node = bucket.firstNode;
  while(node) {
    if(node->data.key == requestedKey) {
      node->data.value = newValue;
    }
    node = node->nextNode;
  }
  ll_append(&bucket, (kvPair){requestedKey, newValue});
}

valueType ht_getValue(int key, hashTable* ht) {
  node* node;
  int bucketNum = hash(key);
  linkedList bucket = ht->bucketArray[bucketNum];
  node = bucket.firstNode;
  while(node) {
    if(node->data.key == key) {
      return node->data.value;
    }
    node = node->nextNode;
  }
  return NO_VALUE;
}
/*
set(key, value)
  bucketNo = hash(key)
  bucket = bucketArray[bucketNo]
  iterate through bucket
    read the value -> check if key is the correct one
    if it is not (continue)
    if it is change this struct value
  if havent set yet
    Create new node and append it

*/