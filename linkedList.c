#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"


linkedList initializeArray(int size){
  node newNode;
  node* previousNode = NULL;
  for(int i = 0; i< size - 1; i++){
    //  Malloc space inside of heap for new variable
    node* nodeLocation = (node*)malloc(sizeof(node) );
    // We set that space to the values for the new struct
    *nodeLocation = (node){0,previousNode};
    
    previousNode = nodeLocation;
  }
  if(size != 0) {
    node* firstNode = (node *)malloc(sizeof(node));
    *firstNode = (node){0, previousNode};
    linkedList lst = {firstNode};
    return lst;
  }
  return (linkedList){NULL};
}

int getSize(linkedList* lst){
  // while() loops here
  struct node* currentNode;
  int i = 0;
  if(i == 0){
    currentNode = lst->firstNode;
  }
  while(currentNode){
    i++;
    currentNode = currentNode->nextNode;
    // git rid of unnecessary copying with ->
  }
  printf("getSize: %d\n", i);
  return i;
}

int getValue(linkedList* lst, int index){
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
  printf("\n%d", nodeContents.data);
  return nodeContents.data;
}
void setValue(linkedList* lst, int data, int index){
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
  printf("\n%d", nodeContents.data);
}
void append(linkedList* lst) {
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
   *newNodeLocation = (node){0, NULL};
   currentNode->nextNode = newNodeLocation;
    // this function doesn't currently work
  } else {
    node* firstNode = (node *)malloc(sizeof(node));
    *firstNode = (node){0, NULL};
    lst->firstNode = firstNode;
  }
}
