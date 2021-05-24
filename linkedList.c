#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#define KVPAIR_NULL ((kvPair){0, 0})

linkedList ll_initializeArray(int size){
  node newNode;
  node* previousNode = NULL;
  for(int i = 0; i< size - 1; i++){
    //  Malloc space inside of heap for new variable
    node* nodeLocation = (node*)malloc(sizeof(node) );
    // We set that space to the values for the new struct
    *nodeLocation = (node){KVPAIR_NULL,previousNode};
    
    previousNode = nodeLocation;
  }
  if(size != 0) {
    node* firstNode = (node *)malloc(sizeof(node));
    *firstNode = (node){KVPAIR_NULL, previousNode};
    linkedList lst = {firstNode};
    return lst;
  }
  return (linkedList){NULL};
}

int ll_getSize(linkedList lst){
  // while() loops here
  struct node* currentNode;
  int i = 0;
  if(i == 0){
    currentNode = lst.firstNode;
  }
  while(currentNode){
    i++;
    currentNode = currentNode->nextNode;
    // git rid of unnecessary copying with ->
  }
  printf("getSize: %d\n", i);
  return i;
}

kvPair ll_getValue(linkedList* lst, int index){
  // while() loop used here not for
  struct node* currentNode; 
  struct node nodeContents;
  int i = 0;
  if(i == 0){
    currentNode = lst->firstNode;
  }
  while(i < index){
    i++;
    nodeContents = *currentNode;
    currentNode = nodeContents.nextNode;
  }
  return nodeContents.data;
}

void ll_setValue(linkedList* lst, kvPair data, int index){
  struct node* currentNode; 
  struct node nodeContents;
  int i = 0;
  if(i == 0){
    currentNode = lst->firstNode;
  }
  while(i < index){
    i++;
    nodeContents = *currentNode;
    currentNode = nodeContents.nextNode;
  }
  nodeContents.data = data;
}

void ll_append(linkedList* lst, kvPair data) {
  struct node* currentNode; 

  if(lst->firstNode) {
    int i = 0;
    // -> === (*ptr).value
    if (i == 0) {
      currentNode = lst->firstNode;
    }
  
    while(currentNode->nextNode) {
      i++;
      currentNode = currentNode->nextNode;
    }
    // GUARANTEE: currentNode is not null AND currentnode->nextNode IS null
    node* newNodeLocation = malloc(sizeof(node));
    *newNodeLocation = (node){data, NULL};
    currentNode->nextNode = newNodeLocation;
    // this function doesn't currently work
  } else {
    node* firstNode = (node *)malloc(sizeof(node));
    *firstNode = (node){data, NULL};
    lst->firstNode = firstNode;
  }
}