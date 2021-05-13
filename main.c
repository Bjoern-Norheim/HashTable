#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

///// 

int main(void) {
  printf("\nZero Array Test\n");
  linkedList zeroArray = initializeArray(0);
  getSize(&zeroArray);
  append(&zeroArray);
  getSize(&zeroArray);

  printf("\nOne Array Test\n");
  linkedList oneArray = initializeArray(1);
  getSize(&oneArray);
  append(&oneArray);
  getSize(&oneArray);

  printf("\nMisc Array Test\n");
  linkedList newArr = initializeArray(8);
  getSize(&newArr);
  setValue(&newArr, 8, 3);
  getValue(&newArr, 3);
  append(&newArr);
  getSize(&newArr);

  linkedList *newArr_ptr = &newArr;
  linkedList newArrCopy = *newArr_ptr;
  return 0;
}